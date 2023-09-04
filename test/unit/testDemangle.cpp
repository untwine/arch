// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/demangle.h>
#include <gtest/gtest.h>

#include <string>

using namespace pxr;

struct MangledStruct {
};
typedef MangledStruct MangledStructAlias;

enum MangledEnum { ONE, TWO, THREE };

template <class T>
class MangledTemplatedClass {
};

// Ad std::string is mangled as 'Ss' on Linux, check that the following
// struct is properly demangled.
struct FooSsSsSsBar {
};

class MangledClass1 {
};

class MangledClass2 {
  public:
    class SubClass {
    };
};

TEST(DemangleTest, Bool)
{
    const std::type_info& typeInfo = typeid(bool);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "bool");
    ASSERT_EQ(ArchGetDemangled(mangledName), "bool");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "bool");
    ASSERT_EQ(ArchGetDemangled<bool>(), "bool");
}

TEST(DemangleTest, Struct)
{
    const std::type_info& typeInfo = typeid(MangledStruct);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "MangledStruct");
    ASSERT_EQ(ArchGetDemangled(mangledName), "MangledStruct");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "MangledStruct");
    ASSERT_EQ(ArchGetDemangled<MangledStruct>(), "MangledStruct");
}

TEST(DemangleTest, StructAlias)
{
    const std::type_info& typeInfo = typeid(MangledStructAlias);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "MangledStruct");
    ASSERT_EQ(ArchGetDemangled(mangledName), "MangledStruct");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "MangledStruct");
    ASSERT_EQ(ArchGetDemangled<MangledStructAlias>(), "MangledStruct");
}

TEST(DemangleTest, Enum)
{
    const std::type_info& typeInfo = typeid(MangledEnum);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "MangledEnum");
    ASSERT_EQ(ArchGetDemangled(mangledName), "MangledEnum");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "MangledEnum");
    ASSERT_EQ(ArchGetDemangled<MangledEnum>(), "MangledEnum");
}

TEST(DemangleTest, String)
{
    const std::type_info& typeInfo = typeid(std::string);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "string");
    ASSERT_EQ(ArchGetDemangled(mangledName), "string");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "string");
    ASSERT_EQ(ArchGetDemangled<std::string>(), "string");
}

TEST(DemangleTest, TemplatedClassString)
{
    const std::type_info& typeInfo = typeid(MangledTemplatedClass<std::string>);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "MangledTemplatedClass<string>");
    ASSERT_EQ(ArchGetDemangled(mangledName), "MangledTemplatedClass<string>");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "MangledTemplatedClass<string>");
    ASSERT_EQ(
        ArchGetDemangled<MangledTemplatedClass<std::string>>(),
        "MangledTemplatedClass<string>");
}

TEST(DemangleTest, StringConfusingMatch)
{
    const std::type_info& typeInfo = typeid(FooSsSsSsBar);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "FooSsSsSsBar");
    ASSERT_EQ(ArchGetDemangled(mangledName), "FooSsSsSsBar");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "FooSsSsSsBar");
    ASSERT_EQ(ArchGetDemangled<FooSsSsSsBar>(), "FooSsSsSsBar");
}

TEST(DemangleTest, Class)
{
    const std::type_info& typeInfo = typeid(MangledClass1);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "MangledClass1");
    ASSERT_EQ(ArchGetDemangled(mangledName), "MangledClass1");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "MangledClass1");
    ASSERT_EQ(
        ArchGetDemangled<MangledClass1>(),
        "MangledClass1");
}

TEST(DemangleTest, SubClass)
{
    const std::type_info& typeInfo = typeid(MangledClass2::SubClass);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "MangledClass2::SubClass");
    ASSERT_EQ(
        ArchGetDemangled(mangledName), "MangledClass2::SubClass");
    ASSERT_EQ(
        ArchGetDemangled(typeInfo), "MangledClass2::SubClass");
    ASSERT_EQ(
        ArchGetDemangled<MangledClass2::SubClass>(),
        "MangledClass2::SubClass");
}

TEST(DemangleTest, Long)
{
    const std::type_info& typeInfo = typeid(unsigned long);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "unsigned long");
    ASSERT_EQ(ArchGetDemangled(mangledName), "unsigned long");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "unsigned long");
    ASSERT_EQ(ArchGetDemangled<unsigned long>(), "unsigned long");
}

TEST(DemangleTest, TemplatedClassInt)
{
    const std::type_info& typeInfo = typeid(MangledTemplatedClass<int>);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    ASSERT_EQ(toBeDemangledName, "MangledTemplatedClass<int>");
    ASSERT_EQ(ArchGetDemangled(mangledName), "MangledTemplatedClass<int>");
    ASSERT_EQ(ArchGetDemangled(typeInfo), "MangledTemplatedClass<int>");
    ASSERT_EQ(
        ArchGetDemangled<MangledTemplatedClass<int>>(),
        "MangledTemplatedClass<int>");
}

TEST(DemangleTest, TemplatedClassRecursiveInt)
{
    const std::type_info& typeInfo =
        typeid(MangledTemplatedClass<MangledTemplatedClass<int>>);
    std::string mangledName = typeInfo.name();
    std::string toBeDemangledName = typeInfo.name();

    ASSERT_TRUE(ArchDemangle(&toBeDemangledName));

    // Since C++11, the parser specification has been improved to be able
    // to interpret multiple right angle brackets in nested template
    // declarations. The implementation of the C++ ABI has been updated
    // accordingly starting with Clang 14 on macOS 13.3
#if defined(MAC_OS_VERSION_13_3)
    const bool improvedAngleBracketDemangling = true;
#else
    const bool improvedAngleBracketDemangling = false;
#endif
    const char* const nestedTemplateTypeName =
        improvedAngleBracketDemangling
            ? "MangledTemplatedClass<MangledTemplatedClass<int>>"
            : "MangledTemplatedClass<MangledTemplatedClass<int> >";

    ASSERT_EQ(toBeDemangledName, nestedTemplateTypeName);
    ASSERT_EQ(ArchGetDemangled(mangledName), nestedTemplateTypeName);
    ASSERT_EQ(ArchGetDemangled(typeInfo), nestedTemplateTypeName);
    ASSERT_EQ(
        ArchGetDemangled<MangledTemplatedClass<MangledTemplatedClass<int>>>(),
        nestedTemplateTypeName);
}

TEST(DemangleTest, IncorrectType)
{
    const char* const badType = "type_that_doesnt_exist";
#if defined(ARCH_OS_WINDOWS)
    ASSERT_EQ(ArchGetDemangled(badType), badType);
#else
    ASSERT_EQ(ArchGetDemangled(badType), "");
#endif
}
