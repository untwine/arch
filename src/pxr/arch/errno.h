// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_ERRNO_H
#define PXR_ARCH_ERRNO_H

/// \file arch/errno.h
/// Functions for dealing with system errors.

#include "./api.h"
#include <string>

namespace pxr {

/// Return the error string for the current value of errno.
///
/// This function provides a thread-safe method of fetching the error string
/// from errno. POSIX.1c defines errno as a macro which provides access to a
/// thread-local integer. This function is thread-safe.
/// \overload
ARCH_API std::string ArchStrerror();

/// Return the error string for the specified value of errno.
///
/// This function is thread-safe.
ARCH_API std::string ArchStrerror(int errorCode);

#if defined(ARCH_OS_WINDOWS)
/// Return the error string for the specified error code.
///
/// This function is thread-safe.
ARCH_API std::string ArchStrSysError(unsigned long errorCode);
#endif

}  // namespace pxr

#endif // PXR_ARCH_ERRNO_H
