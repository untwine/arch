// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/arch/threads.h>
#include <pxr/arch/error.h>

using namespace pxr;

int main()
{
    ARCH_AXIOM(ArchIsMainThread());

    return 0;
}

