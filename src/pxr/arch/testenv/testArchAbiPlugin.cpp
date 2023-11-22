//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include <pxr/arch/export.h>
#include <pxr/arch/testArchAbi.h>


using namespace pxr;

extern "C" {

ARCH_EXPORT ArchAbiBase2* newDerived() { return new ArchAbiDerived<int>; }

}
