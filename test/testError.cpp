// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Written by dhl (10 Jul 2006)
// Modified by Jeremy Retailleau.

#include <pxr/arch/error.h>
#include "./testArchUtil.h"

using namespace pxr;

int main(int argc, char** argv)
{
    ArchTestCrashArgParse(argc, argv);
    ArchTestCrash(ArchTestCrashMode::Error);
}
