// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_ENV_H
#define PXR_ARCH_ENV_H

#include "./api.h"

#include <string>

namespace pxr {

///
/// Architecture dependent access to environment variables.
///
/// Returns \c true if and only if the current environment contains \c name.
ARCH_API
bool
ArchHasEnv(const std::string &name);

/// Gets a value from the current environment identified by \c name.
ARCH_API
std::string
ArchGetEnv(const std::string &name);

/// Creates or modifies an environment variable.
ARCH_API
bool
ArchSetEnv(const std::string &name, const std::string &value, bool overwrite);

/// Removes an environment variable.
ARCH_API
bool
ArchRemoveEnv(const std::string &name);

/// Expands environment variables in \c str.
ARCH_API
std::string
ArchExpandEnvironmentVariables(const std::string& str);

/// Return an array of the environment variables.
ARCH_API
char**
ArchEnviron();

}  // namespace pxr

#endif // PXR_ARCH_ENV_H
