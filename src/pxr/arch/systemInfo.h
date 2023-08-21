// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_SYSTEM_INFO_H
#define PXR_ARCH_SYSTEM_INFO_H

/// \file arch/systemInfo.h
/// Provide architecture-specific system information.

#include "./api.h"
#include <string>

namespace pxr {

/// Return current working directory as a string.
ARCH_API
std::string ArchGetCwd();

/// Return the path to the program's executable.
ARCH_API
std::string ArchGetExecutablePath();

/// Return the system's memory page size.  Safe to assume power-of-two.
ARCH_API
int ArchGetPageSize();

}  // namespace pxr

#endif // PXR_ARCH_SYSTEM_INFO_H
