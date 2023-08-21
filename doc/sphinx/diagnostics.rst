.. _diagnostics:

***********
Diagnostics
***********

Functions having to do with error reporting/handling.

.. _diagnostics/files:

Files
~~~~~

* :arch-cpp:`error.h`
* :arch-cpp:`stackTrace.h`
* :arch-cpp:`symbols.h`

.. _diagnostics/macros:

Macros
~~~~~~

* :arch-cpp:`ARCH_ERROR`
* :arch-cpp:`ARCH_WARNING`
* :arch-cpp:`ARCH_AXIOM`

.. _diagnostics/typedefs:

Typedefs
~~~~~~~~

* :arch-cpp:`ArchStackTraceCallback`
* :arch-cpp:`ArchCrashHandlerSystemCB`

.. _diagnostics/functions:

Functions
~~~~~~~~~

* :arch-cpp:`ArchLogFatalProcessState`
* :arch-cpp:`ArchLogCurrentProcessState`
* :arch-cpp:`ArchSetProcessStateLogCommand`
* :arch-cpp:`ArchIsAppCrashing`
* :arch-cpp:`ArchLogSessionInfo`
* :arch-cpp:`ArchSetLogSession`
* :arch-cpp:`ArchEnableSessionLogging`
* :arch-cpp:`ArchPrintStackTrace(FILE*, const std::string&, const std::string&)`
* :arch-cpp:`ArchPrintStackTrace(FILE*, const std::string&)`
* :arch-cpp:`ArchPrintStackTrace(std::ostream&, const std::string&, const std::string&)`
* :arch-cpp:`ArchPrintStackTrace(std::ostream&, const std::string&)`
* :arch-cpp:`ArchSetStackTraceCallback`
* :arch-cpp:`ArchGetStackTraceCallback`
* :arch-cpp:`ArchGetAppLaunchTime`
* :arch-cpp:`ArchSetFatalStackLogging`
* :arch-cpp:`ArchGetFatalStackLogging`
* :arch-cpp:`ArchSetProgramNameForErrors`
* :arch-cpp:`ArchGetProgramNameForErrors`
* :arch-cpp:`ArchSetProgramInfoForErrors`
* :arch-cpp:`ArchGetProgramInfoForErrors`
* :arch-cpp:`ArchSetExtraLogInfoForErrors`
* :arch-cpp:`ArchLogStackTrace(const std::string&, const std::string&, bool = false, const std::string& = "")`
* :arch-cpp:`ArchLogStackTrace(const std::string&, bool = false, const std::string& = "")`
* :arch-cpp:`ArchGetStackTrace`
* :arch-cpp:`ArchGetStackFrames(size_t, std::vector< uintptr_t >*)`
* :arch-cpp:`ArchGetStackFrames(size_t, uintptr_t*)`
* :arch-cpp:`ArchGetStackFrames(size_t, size_t, std::vector< uintptr_t >*)`
* :arch-cpp:`ArchGetStackFrames(size_t, size_t, uintptr_t*)`
* :arch-cpp:`ArchPrintStackFrames`
* :arch-cpp:`ArchCrashHandlerSystemv`
* :arch-cpp:`ArchGetAddressInfo`
