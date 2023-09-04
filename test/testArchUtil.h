// Copyright 2017 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_TEST_ARCH_UTIL_H
#define PXR_ARCH_TEST_ARCH_UTIL_H

#include <pxr/arch/api.h>

namespace pxr {

// Crash types.
enum class ArchTestCrashMode {
    Error,
    ReadInvalidAddresses,
    ReadInvalidAddressesWithThread
};

// Cause the test to crash deliberately.
ARCH_API void ArchTestCrash(ArchTestCrashMode mode);

// On Windows we can't easily fork() so we just run the test again with
// command line arguments to request a crash.
ARCH_API void ArchTestCrashArgParse(int argc, char** argv);

}  // namespace pxr

#endif // PXR_ARCH_TEST_ARCH_UTIL_H
