//
// Copyright 2017 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef PXR_ARCH_TEST_ARCH_UTIL_H
#define PXR_ARCH_TEST_ARCH_UTIL_H

namespace pxr {

// Crash types.
enum class ArchTestCrashMode {
    Error,
    ReadInvalidAddresses,
    ReadInvalidAddressesWithThread
};

// Cause the test to crash deliberately.
void ArchTestCrash(ArchTestCrashMode mode);

// On Windows we can't easily fork() so we just run the test again with
// command line arguments to request a crash.
void ArchTestCrashArgParse(int argc, char** argv);

}  // namespace pxr

#endif // PXR_ARCH_TEST_ARCH_UTIL_H
