// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_SYMBOLS_H
#define PXR_ARCH_SYMBOLS_H

/// \file arch/symbols.h
/// Architecture-specific symbol lookup routines.

#include "./api.h"
#include <string>

namespace pxr {

/// Returns information about the address \p address in the running program.
///
/// Returns \c false if no information can be found, otherwise returns \c true
/// and modifies the other arguments: \p objectPath is set to the absolute path 
/// to the executable or library the address is found in, \p baseAddress is the
/// address where that object is loaded, \p symbolName is the symbolic name of
/// the thing containing the address, and \p symbolAddress is the starting
/// address of that thing.  If no thing is found to contain the address then
/// \p symbolName is cleared and \p symbolAddress is set to \c NULL. Any of
/// the arguments except \p address can be \c NULL if the result isn't needed.
/// This will return \c false if \c NULL is passed to \p address.
///
ARCH_API
bool ArchGetAddressInfo(void* address,
                        std::string* objectPath, void** baseAddress,
                        std::string* symbolName, void** symbolAddress);

}  // namespace pxr

#endif // PXR_ARCH_SYMBOLS_H
