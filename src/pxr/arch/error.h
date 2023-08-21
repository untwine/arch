// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_ERROR_H
#define PXR_ARCH_ERROR_H

/// \file arch/error.h
/// Low-level fatal error reporting.

#include "./api.h"
#include "./defines.h"
#include "./functionLite.h"
#include <stddef.h>

namespace pxr {

/// Print message to standard error and abort program.
///
/// \param msg The reason for the failure.
/// \param funcName The name of the function that \c Arch_Error was called from.
/// \param lineNo The line number of the file that \c Arch_Error was called from.
/// \param fileName The name of the file that \c Arch_Error was called from.
///
/// \private
[[noreturn]]
ARCH_API
void Arch_Error(const char* msg, const char* funcName,
                size_t lineNo, const char* fileName);

/// Print warning message to standard error, but continue execution.
///
/// \param msg The reason for the warning.
/// \param funcName The name of the function that \c Arch_Warning was called from.
/// \param lineNo The line number of the file that \c Arch_Warning was called from.
/// \param fileName The name of the file that \c Arch_Warning was called from.
///
/// \private
ARCH_API
void Arch_Warning(const char* msg, const char* funcName,
                  size_t lineNo, const char* fileName);

/// Unconditionally aborts the program.
///
/// \param msg is a literal string, a \c const \c char* (but not
///        an \c std::string) that describes why the program is aborting.
/// \hideinitializer
#define ARCH_ERROR(msg) \
    pxr::Arch_Error(msg, __ARCH_FUNCTION__, __LINE__, __ARCH_FILE__)

/// Prints a warning message to stderr.
///
/// \param msg is a literal string, a \c const \c char* (but not
///        an \c std::string).
/// \hideinitializer
#define ARCH_WARNING(msg) \
    pxr::Arch_Warning(msg, __ARCH_FUNCTION__, __LINE__, __ARCH_FILE__)

/// Aborts the program if \p cond evaluates to false.
/// \hideinitializer
#define ARCH_AXIOM(cond) \
    if (!(cond)) ARCH_ERROR("[" #cond "] axiom failed")

}  // namespace pxr

#endif // PXR_ARCH_ERROR_H
