// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include "./testArchAbi.h"
#include <pxr/arch/error.h>
#include <pxr/arch/library.h>
#include <pxr/arch/systemInfo.h>
#include <pxr/arch/vsnprintf.h>

#include <iostream>
#include <typeinfo>

using namespace pxr;

typedef ArchAbiBase2* (*NewDerived)();

int
main(int /*argc*/, char** /*argv*/)
{
    // Compute the plugin directory.
    std::string path = ArchGetExecutablePath();
    // Get directories.
    path = path.substr(0, path.find_last_of("/\\"));

    // Load the plugin and get the factory function.
#if defined(ARCH_OS_WINDOWS)
    path += "\\testArchAbiPlugin.dll";
#elif defined(ARCH_OS_DARWIN)
    path += "/libtestArchAbiPlugin.dylib";
#else
    path += "/libtestArchAbiPlugin.so";
#endif
    auto plugin = ArchLibraryOpen(path, ARCH_LIBRARY_LAZY);
    if (!plugin) {
        std::string error = ArchLibraryError();
        std::cerr << "Failed to load plugin: " << error << std::endl;
        ARCH_AXIOM(plugin);
    }

    NewDerived newPluginDerived = (NewDerived)ArchLibraryGetSymbolAddress(
        plugin, "newDerived");
    if (!newPluginDerived) {
        std::cerr << "Failed to find factory symbol" << std::endl;
        ARCH_AXIOM(newPluginDerived);
    }

    // Create a derived object in this executable and in the plugin.
    ArchAbiBase2* mainDerived = new ArchAbiDerived<int>;
    ArchAbiBase2* pluginDerived = newPluginDerived();

    // Compare.  The types should be equal and the dynamic cast should not
    // change the pointer.
    std::cout
        << "Derived types are equal: "
        << ((typeid(*mainDerived) == typeid(*pluginDerived)) ? "yes" : "no")
        << ", cast: " << pluginDerived
        << "->" << dynamic_cast<ArchAbiDerived<int>*>(pluginDerived)
        << std::endl;
    ARCH_AXIOM(typeid(*mainDerived) == typeid(*pluginDerived));
    ARCH_AXIOM(pluginDerived == dynamic_cast<ArchAbiDerived<int>*>(pluginDerived));

    return 0;
}
