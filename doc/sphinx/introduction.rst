.. _introduction:

************
Introduction
************

The arch library is a repository for all architecture-dependent code. It
isolates all platform dependencies (and confusing #ifdefs) into one small
library and also serves as a common area for documentation of these
multi-platform issues.

The high-level grouping of the classes/functions is:

* :ref:`bits`
* :ref:`multithreading`
* :ref:`math`
* :ref:`strings`
* :ref:`system_functions`
* :ref:`memory_management`
* :ref:`diagnostics`
* :ref:`symbol_visibility`

Symbols for use within ``libarch``:

For OS:

* ``ARCH_OS_LINUX``
* ``ARCH_OS_DARWIN``
* ``ARCH_OS_WINDOWS``

For processor:

* ``ARCH_CPU_INTEL``
* ``ARCH_CPU_ARM``

For bits:

* ``ARCH_BITS_64``

For compiler:

* ``ARCH_COMPILER_CLANG``

    * ``ARCH_COMPILER_CLANG_MAJOR``
    * ``ARCH_COMPILER_CLANG_MINOR``
    * ``ARCH_COMPILER_CLANG_PATCHLEVEL``

* ``ARCH_COMPILER_GCC``

    * ``ARCH_COMPILER_GCC_MAJOR``
    * ``ARCH_COMPILER_GCC_MINOR``
    * ``ARCH_COMPILER_GCC_PATCHLEVEL``

* ``ARCH_COMPILER_MSVC``

    * ``ARCH_COMPILER_MSVC_VERSION``

* ``ARCH_COMPILER_ICC``
