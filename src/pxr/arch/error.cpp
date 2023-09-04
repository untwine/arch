// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include "./error.h"
#include "./debugger.h"
#include <stdio.h>

namespace pxr {

void
Arch_Error(const char* cond, const char* funcName, size_t lineNo, const char* fileName)
{
    fprintf(stderr, " ArchError: %s\n", cond);
    fprintf(stderr, "  Function: %s\n", funcName);
    fprintf(stderr, "      File: %s\n", fileName);
    fprintf(stderr, "      Line: %zu\n", lineNo);
    ArchAbort();
}

void
Arch_Warning(const char* cond, const char* funcName, size_t lineNo, const char* fileName)
{
    fprintf(stderr, " ArchWarn: %s\n", cond);
    fprintf(stderr, " Function: %s\n", funcName);
    fprintf(stderr, "     File: %s\n", fileName);
    fprintf(stderr, "     Line: %zu\n", lineNo);
}

}  // namespace pxr
