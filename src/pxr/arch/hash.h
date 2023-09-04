// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_ARCH_HASH_H
#define PXR_ARCH_HASH_H

/// \file arch/hash.h
/// Hash functions.

#include "./api.h"
#include "./inttypes.h"

namespace pxr {

/// Hash \a len bytes of \a data.
///
/// To compute a hash value for data that is not contiguous in memory, iterate
/// over all the contiguous blocks of memory and accumulate the hash value by
/// passing it on as \p seed.  Note that this is *not* equivalent to hashing the
/// contiguous pieces as a whole.  Support for that may be added in future.
///
ARCH_API uint32_t ArchHash(const char *data, size_t len);
/// \overload
ARCH_API uint32_t ArchHash(const char *data, size_t len, uint32_t seed);

/// Hash \a len bytes of \a data.
///
/// To compute a hash value for data that is not contiguous in memory, iterate
/// over all the contiguous blocks of memory and accumulate the hash value by
/// passing it on as \p seed.  Note that this is *not* equivalent to hashing the
/// contiguous pieces as a whole.  Support for that may be added in future.
///
ARCH_API uint64_t ArchHash64(const char *data, size_t len);
/// \overload
ARCH_API uint64_t ArchHash64(const char *data, size_t len, uint64_t seed);

}  // namespace pxr

#endif // PXR_ARCH_HASH_H
