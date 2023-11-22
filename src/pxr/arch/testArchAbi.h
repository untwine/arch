//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef PXR_ARCH_TEST_ARCH_ABI_H
#define PXR_ARCH_TEST_ARCH_ABI_H

#include "./api.h"

namespace pxr {

struct ArchAbiBase1 {
    void* dummy;
};

struct ArchAbiBase2 {
    virtual ~ArchAbiBase2() { }
    virtual const char* name() const = 0;
};

template <class T>
struct ArchAbiDerived : public ArchAbiBase1, public ArchAbiBase2 {
    virtual ~ArchAbiDerived() { }
    virtual const char* name() const { return "ArchAbiDerived"; }
};

}  // namespace pxr

#endif // PXR_ARCH_TEST_ARCH_ABI_H
