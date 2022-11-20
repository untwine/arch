// Copyright 2022 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
// Modified by Jeremy Retailleau

#ifndef ARCH_ERRNO_H
#define ARCH_ERRNO_H

/// \file arch/errno.h
/// \ingroup group_SystemFunctions
/// Functions for dealing with system errors.

#include <string>

#include "arch/api.h"

namespace arch {

/// \addtogroup group_SystemFunctions
///@{

/// Return the error string for the current value of errno.
///
/// This function provides a thread-safe method of fetching the error string
/// from errno. POSIX.1c defines errno as a macro which provides access to a
/// thread-local integer. This function is thread-safe.
/// \overload
ARCH_API std::string StrError();

/// Return the error string for the specified value of errno.
///
/// This function is thread-safe.
ARCH_API std::string StrError(int errorCode);

#if defined(ARCH_OS_WINDOWS)
/// Return the error string for the specified error code.
///
/// This function is thread-safe.
ARCH_API std::string StrSysError(unsigned long errorCode);
#endif

///@}

}  // namespace arch

#endif  // ARCH_ERRNO_H
