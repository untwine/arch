// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_LIBRARY_H
#define PXR_ARCH_LIBRARY_H

#include "./api.h"

#include <string>

#if defined(ARCH_OS_WINDOWS)
#   define ARCH_LIBRARY_LAZY    0
#   define ARCH_LIBRARY_NOW     0
#   define ARCH_LIBRARY_LOCAL   0
#   define ARCH_LIBRARY_GLOBAL  0
#   define ARCH_LIBRARY_SUFFIX  ".dll"
#   define ARCH_STATIC_LIBRARY_SUFFIX ".lib"
#else
#   include <dlfcn.h>
#   define ARCH_LIBRARY_LAZY    RTLD_LAZY
#   define ARCH_LIBRARY_NOW     RTLD_NOW
#   define ARCH_LIBRARY_LOCAL   RTLD_LOCAL
#   define ARCH_LIBRARY_GLOBAL  RTLD_GLOBAL
#   if defined(ARCH_OS_DARWIN)
#       define ARCH_LIBRARY_SUFFIX  ".dylib"
#   else
#       define ARCH_LIBRARY_SUFFIX  ".so"
#   endif
#   define ARCH_STATIC_LIBRARY_SUFFIX ".a"
#endif

// On MacOS shared libraries and loadable modules (aka loadable bundles aka
// plugins) are different entities. Most cross-platform software packages
// that create  loadable modules use .so as the extension on MacOS for
// compatibility, so we use that here.
#if defined(ARCH_OS_DARWIN)
#   define ARCH_PLUGIN_SUFFIX ".so"
#else
#   define ARCH_PLUGIN_SUFFIX ARCH_LIBRARY_SUFFIX
#endif

namespace pxr {

/// library.h
/// Architecture dependent loading and unloading of dynamic libraries.

/// Load an executable object file.
///
/// Opens the dynamic library that is specified by filename.
/// Returning the handle to the module if successful; false otherwise.
ARCH_API 
void* ArchLibraryOpen(const std::string &filename, int flag);

/// Obtain a description of the most recent error that occurred from
/// \c ArchLibraryOpen.
ARCH_API
std::string ArchLibraryError();

/// Closes an object opened with \c ArchLibraryOpen.
ARCH_API
int ArchLibraryClose(void* handle);

/// Obtain the address of a symbol defined within an object opened with
/// \c ArchLibraryOpen.
///
/// Obtain the address of a symbol that is specified by name.
/// Returning the address of the symbol if successful; nullptr otherwise.
ARCH_API
void* ArchLibraryGetSymbolAddress(void* handle, const char* name);

}  // namespace pxr

#endif // PXR_ARCH_LIBRARY_H
