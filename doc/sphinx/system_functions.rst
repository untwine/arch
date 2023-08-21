.. _system_functions:

****************
System Functions
****************

Functions that encapsulate differing low-level system calls.

.. _system_functions/files:

Files
~~~~~

* :arch-cpp:`errno.h`
* :arch-cpp:`fileSystem.h`
* :arch-cpp:`systemInfo.h`
* :arch-cpp:`timing.h`
* :arch-cpp:`virtualMemory.h`

.. _system_functions/classes:

Classes
~~~~~~~

* :arch-cpp:`ArchIntervalTimer`

.. _system_functions/macros:

Macros
~~~~~~

* :arch-cpp:`ARCH_GLOB_NOCHECK`
* :arch-cpp:`ARCH_GLOB_MARK`
* :arch-cpp:`ARCH_GLOB_NOSORT`
* :arch-cpp:`ARCH_GLOB_DEFAULT`
* :arch-cpp:`ARCH_PATH_MAX`
* :arch-cpp:`ARCH_PATH_SEP`
* :arch-cpp:`ARCH_PATH_LIST_SEP`
* :arch-cpp:`ARCH_REL_PATH_IDENT`

.. _system_functions/typedefs:

Typedefs
~~~~~~~~

* :arch-cpp:`ArchStatType`
* :arch-cpp:`ArchConstFileMapping`
* :arch-cpp:`ArchMutableFileMapping`

.. _system_functions/enumerations:

Enumerations
~~~~~~~~~~~~

* :arch-cpp:`ArchMemAdvice`
* :arch-cpp:`ArchFileAdvice`

.. _system_functions/functions:

Functions
~~~~~~~~~

* :arch-cpp:`ArchHasEnv`
* :arch-cpp:`ArchGetEnv`
* :arch-cpp:`ArchSetEnv`
* :arch-cpp:`ArchRemoveEnv`
* :arch-cpp:`ArchExpandEnvironmentVariables`
* :arch-cpp:`ArchStrerror()`
* :arch-cpp:`ArchStrerror(int)`
* :arch-cpp:`ArchOpenFile`
* :arch-cpp:`ArchGetFileLength(const char*)`
* :arch-cpp:`ArchGetFileLength(FILE*)`
* :arch-cpp:`ArchGetFileName`
* :arch-cpp:`ArchStatIsWritable`
* :arch-cpp:`ArchGetModificationTime(const char*, double*)`
* :arch-cpp:`ArchGetModificationTime(const ArchStatType&)`
* :arch-cpp:`ArchNormPath`
* :arch-cpp:`ArchAbsPath`
* :arch-cpp:`ArchGetStatMode`
* :arch-cpp:`ArchGetTmpDir`
* :arch-cpp:`ArchMakeTmpFileName`
* :arch-cpp:`ArchMakeTmpFile(const std::string&, std::string* = nullptr)`
* :arch-cpp:`ArchMakeTmpFile(const std::string&, const std::string&, std::string* = nullptr)`
* :arch-cpp:`ArchMakeTmpSubdir`
* :arch-cpp:`ArchGetFileMappingLength(ArchConstFileMapping const &)`
* :arch-cpp:`ArchGetFileMappingLength(ArchMutableFileMapping const &)`
* :arch-cpp:`ArchMapFileReadOnly(FILE*, std::string* = nullptr)`
* :arch-cpp:`ArchMapFileReadOnly(std::string const &, std::string* = nullptr)`
* :arch-cpp:`ArchMapFileReadWrite(FILE*, std::string* = nullptr)`
* :arch-cpp:`ArchMapFileReadWrite(std::string const &, std::string* = nullptr)`
* :arch-cpp:`ArchMemAdvise`
* :arch-cpp:`ArchQueryMappedMemoryResidency`
* :arch-cpp:`ArchPRead`
* :arch-cpp:`ArchPWrite`
* :arch-cpp:`ArchReadLink`
* :arch-cpp:`ArchFileAdvise`
* :arch-cpp:`ArchLibraryOpen`
* :arch-cpp:`ArchLibraryError`
* :arch-cpp:`ArchLibraryClose`
* :arch-cpp:`ArchLibraryGetSymbolAddress`
* :arch-cpp:`ArchGetCwd`
* :arch-cpp:`ArchGetExecutablePath`
* :arch-cpp:`ArchGetPageSize`
* :arch-cpp:`ArchGetTickTime`
* :arch-cpp:`ArchGetStartTickTime`
* :arch-cpp:`ArchGetStopTickTime`
* :arch-cpp:`ArchGetTickQuantum`
* :arch-cpp:`ArchGetIntervalTimerTickOverhead`
* :arch-cpp:`ArchTicksToNanoseconds`
* :arch-cpp:`ArchTicksToSeconds`
* :arch-cpp:`ArchSecondsToTicks`
* :arch-cpp:`ArchMeasureExecutionTime`
