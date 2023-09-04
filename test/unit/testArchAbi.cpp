// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/library.h>
#include <pxr/arch/systemInfo.h>
#include <archTest/abi.h>
#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace pxr;

TEST(ArchABITest, GetExecutablePath)
{
    std::string path = ArchGetExecutablePath();
    std::string root = std::getenv("EXE_PATH");
#if defined(ARCH_OS_WINDOWS)
    std::string expected = root + "\\testArchAbi.exe";
#else
    std::string expected = root + "/testArchAbi";
#endif
    ASSERT_EQ(path, expected);
}

TEST(ArchABITest, Library)
{
    std::string path = std::getenv("PLUGIN_PATH");
#if defined(ARCH_OS_WINDOWS)
    path += "\\archTestPlugin.dll";
#elif defined(ARCH_OS_DARWIN)
    path += "/libarchTestPlugin.dylib";
#else
    path += "/libarchTestPlugin.so";
#endif
    auto plugin = ArchLibraryOpen(path, ARCH_LIBRARY_LAZY);
    ASSERT_NE(plugin, nullptr);
    ASSERT_EQ(ArchLibraryError(), "");

    // Get symbol from library.
    using NewDerived = ArchAbiBase2* (*)();
    auto newPluginDerived =
        (NewDerived)ArchLibraryGetSymbolAddress(plugin, "newDerived");
    ASSERT_NE(newPluginDerived, nullptr);

    // Fail to get symbol from library.
    auto symbol =
        (NewDerived)ArchLibraryGetSymbolAddress(plugin, "incorrect");
    ASSERT_EQ(symbol, nullptr);

    // Create a derived object in this executable and in the plugin.
    ArchAbiBase2* mainDerived = new ArchAbiDerived<int>;
    ArchAbiBase2* pluginDerived = newPluginDerived();

    // The types should be equal and the dynamic cast should not
    // change the pointer.
    ASSERT_EQ(typeid(*mainDerived), typeid(*pluginDerived));
    ASSERT_EQ(
        pluginDerived, dynamic_cast<ArchAbiDerived<int>*>(pluginDerived));

    auto status = ArchLibraryClose(plugin);
    ASSERT_EQ(status, 0);
}

TEST(ArchABITest, LibraryOpenError)
{
    std::string path = "/incorrect";
    auto plugin = ArchLibraryOpen(path, ARCH_LIBRARY_LAZY);
    ASSERT_EQ(plugin, nullptr);
    ASSERT_NE(ArchLibraryError(), "");
}
