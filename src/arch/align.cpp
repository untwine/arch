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

#include "arch/align.h"

#include "arch/defines.h"
#include "arch/error.h"

#if defined(ARCH_OS_DARWIN)
#include <sys/malloc.h>
#else
#include <malloc.h>
#endif /* defined(ARCH_OS_DARWIN) */

#include <cstdlib>

namespace arch {

/// Aligned memory allocation.
void* AlignedAlloc(size_t alignment, size_t size)
{
#if defined(ARCH_OS_DARWIN)                            \
    || (defined(ARCH_OS_LINUX) && defined(__GLIBCXX__) \
        && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
    // alignment must be >= sizeof(void*)
    if (alignment < sizeof(void*)) {
        alignment = sizeof(void*);
    }

    void* pointer;
    if (posix_memalign(&pointer, alignment, size) == 0) {
        return pointer;
    }

    return nullptr;
#elif defined(ARCH_OS_WINDOWS)
    return _aligned_malloc(size, alignment);
#else
    return aligned_alloc(alignment, size);
#endif
}

/// Free memory allocated by AlignedAlloc.
void AlignedFree(void* ptr)
{
#if defined(ARCH_OS_DARWIN)                            \
    || (defined(ARCH_OS_LINUX) && defined(__GLIBCXX__) \
        && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
    free(ptr);
#elif defined(ARCH_OS_WINDOWS)
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}

}  // namespace arch
