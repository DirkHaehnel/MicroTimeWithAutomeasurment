/*
 * Copyright (c) 2009,
 * National Instruments Corporation.
 * All rights reserved.
 */

#ifndef __NiFpga_h__
#define __NiFpga_h__

/*
 * Determine platform details.
 */
#if defined(_M_IX86) \
 || defined(_M_X64) \
 || defined(i386) \
 || defined(__i386__) \
 || defined(__amd64__) \
 || defined(__amd64) \
 || defined(__x86_64__) \
 || defined(__x86_64) \
 || defined(__i386) \
 || defined(_X86_) \
 || defined(__THW_INTEL__) \
 || defined(__I86__) \
 || defined(__INTEL__) \
 || defined(__X86__) \
 || defined(__386__) \
 || defined(__I86__) \
 || defined(M_I386) \
 || defined(M_I86) \
 || defined(_M_I386) \
 || defined(_M_I86)
   #define NiFpga_Intel 1
   #if defined(PHARLAPOS)
      #define NiFpga_Ets 1
   #elif defined(_WIN32) \
      || defined(_WIN64) \
      || defined(__WIN32__) \
      || defined(__TOS_WIN__) \
      || defined(__WINDOWS__) \
      || defined(_WINDOWS) \
      || defined(__WINDOWS_386__)
      #define NiFpga_Windows 1
   #else
      #error Unsupported OS.
   #endif
#elif defined(__powerpc) \
   || defined(__powerpc__) \
   || defined(__POWERPC__) \
   || defined(__ppc__) \
   || defined(__PPC) \
   || defined(_M_PPC) \
   || defined(_ARCH_PPC) \
   || defined(__PPC__) \
   || defined(__ppc)
   #define NiFpga_Ppc 1
   #if defined(__vxworks)
      #define NiFpga_VxWorks 1
   #else
      #error Unsupported OS.
   #endif
#else
   #error Unsupported architecture.
#endif

/*
 * Determine compiler.
 */
#if defined(_CVI_)
   #define NiFpga_Cvi 1
#elif defined(_MSC_VER)
   #define NiFpga_Msvc 1
#elif defined(__GNUC__)
   #define NiFpga_Gcc 1
#else
   /* Unknown compiler. */
#endif

/*
 * Determine compliance with different C/C++ language standards.
 */
#if defined(__cplusplus)
   #define NiFpga_Cpp 1
   #if __cplusplus >= 199707L
      #define NiFpga_Cpp98 1
   #endif
#endif
#if defined(__STDC__)
   #define NiFpga_C89 1
   #if defined(__STDC_VERSION__)
      #define NiFpga_C90 1
      #if __STDC_VERSION__ >= 199409L
         #define NiFpga_C94 1
         #if __STDC_VERSION__ >= 199901L
            #define NiFpga_C99 1
         #endif
      #endif
   #endif
#endif
#if !NiFpga_Cpp
   /* const was added in C89, but MSVC doesn't define the standard macro. */
   #if !NiFpga_C89 && !NiFpga_Msvc
      #define const
   #endif
   /* inline was added in C99, but GCC has had it for years. */
   #if !NiFpga_C99 && !NiFpga_Gcc
      #define inline
   #endif
#endif

/*
 * Define standard integer types.
 */
#if NiFpga_C99 \
 || NiFpga_VxWorks && NiFpga_Gcc
   #include <stdint.h>
#elif NiFpga_Cvi
   typedef   signed    char int8_t;
   typedef unsigned    char uint8_t;
   typedef   signed   short int16_t;
   typedef unsigned   short uint16_t;
   typedef   signed     int int32_t;
   typedef unsigned     int uint32_t;
   typedef   signed __int64 int64_t;
   typedef unsigned __int64 uint64_t;
#elif NiFpga_Msvc
   typedef   signed __int8  int8_t;
   typedef unsigned __int8  uint8_t;
   typedef   signed __int16 int16_t;
   typedef unsigned __int16 uint16_t;
   typedef   signed __int32 int32_t;
   typedef unsigned __int32 uint32_t;
   typedef   signed __int64 int64_t;
   typedef unsigned __int64 uint64_t;
#else
   /* Integer types must be defined by the client. */
#endif

#if NiFpga_Cpp
extern "C" {
#endif

/**
 * A boolean value; either NiFpga_False or NiFpga_True.
 */
typedef uint32_t NiFpga_Bool;

/**
 * Represents a false condition.
 */
static const NiFpga_Bool NiFpga_False = 0;

/**
 * Represents a true condition.
 */
static const NiFpga_Bool NiFpga_True = 1;

/**
 * The result of a function. Negative values are errors and positive values are
 * warnings.
 */
typedef int32_t NiFpga_Status;

/**
 * No errors or warnings.
 */
static const NiFpga_Status NiFpga_Status_Success = 0;

/**
 * A memory allocation failed.
 */
static const NiFpga_Status NiFpga_Status_MemoryFull = -52000;

/**
 * The requested feature is not supported.
 */
static const NiFpga_Status NiFpga_Status_FeatureUnsupported = -52002;

/**
 * An unexpected software error occurred.
 */
static const NiFpga_Status NiFpga_Status_SoftwareFault = -52003;

/**
 * The parameter to a function was invalid.
 */
static const NiFpga_Status NiFpga_Status_InvalidParameter = -52005;

/**
 * A needed resource was not found. This could be the NiFpga.dll/NiFpga.out
 * library, or the .lvbitx bitfile.
 */
static const NiFpga_Status NiFpga_Status_ResourceNotFound = -52006;

/**
 * A needed resource was not properly initialized. This could occur if
 * NiFpga_Initialize was not called.
 */
static const NiFpga_Status NiFpga_Status_ResourceNotInitialized = -52010;

/**
 * An error was detected in the communication between the host
 * computer and the FPGA target.
 *
 * If you are using any external clocks, make sure they are connected
 * and within the supported specifications. Also, verify that the rate
 * of any external clocks match the specified clock rates. If you are
 * generating your clocks internally, please contact National
 * Instruments Technical Support.
 */
static const NiFpga_Status NiFpga_Status_FpgaCommTimeout = -61046;

/**
 * The FPGA is busy.
 */
static const NiFpga_Status NiFpga_Status_FpgaBusy = -61141;

/**
 * An unexpected internal error occurred.
 */
static const NiFpga_Status NiFpga_Status_FpgaInternalError = -61499;

/**
 * Tests whether a status is fatal. Errors are fatal but warnings are not.
 *
 * @param status status to check for fatal
 */
static inline NiFpga_Bool NiFpga_IsFatal(const NiFpga_Status status)
{
   return status < NiFpga_Status_Success;
}

/**
 * Tests whether a status is non-fatal. Success and warnings are not fatal.
 *
 * @param status status to check for fatal
 */
static inline NiFpga_Bool NiFpga_IsNotFatal(const NiFpga_Status status)
{
   return status >= NiFpga_Status_Success;
}

/**
 * Conditionally sets the status to a new value. The previous status will be
 * preserved unless the new status is "more fatal". This means that warnings or
 * errors will overwrite successes, and only errors will overwrite warnings.
 * Errors will never be overwritten with new errors, and warnings will never be
 * overwritten with new warnings.
 *
 * @param status status to conditionally set
 * @param newStatus new status value that may be set
 */
static inline NiFpga_Status NiFpga_SetStatus(NiFpga_Status* const status,
                                             const NiFpga_Status  newStatus)
{
   if (!status)
   {
      return NiFpga_Status_InvalidParameter;
   }
   if (NiFpga_IsNotFatal(*status)
   &&  (*status == NiFpga_Status_Success || NiFpga_IsFatal(newStatus)))
   {
      *status = newStatus;
   }
   return *status;
}

/**
 * Only evaluates the expression if the status is not fatal. The expression
 * must evalutate to an NiFpga_Status, such as a call to any NiFpga_* function,
 * as the status will be set to the returned status if the expression is
 * evaluated.
 *
 * This macro can be used to mimic status chaining in LabVIEW, where the status
 * doesn't have to be explicitly checked after each call. Such code may look as
 * follows:
 *
 *    NiFpga_Status status = NiFpga_Status_Success;
 *    NiFpga_IfIsNotFatal(status, NiFpga_WriteU32(...));
 *    NiFpga_IfIsNotFatal(status, NiFpga_WriteU32(...));
 *    NiFpga_IfIsNotFatal(status, NiFpga_WriteU32(...));
 *
 * @param status status to check for fatal
 * @param expression expression to call if the incoming status is not fatal
 */
#define NiFpga_IfIsNotFatal(status, expression) \
   if (NiFpga_IsNotFatal(status)) \
   { \
      NiFpga_SetStatus(&status, (expression)); \
   }

/**
 * This must be called before all other function calls.
 *
 * @warning This function is not thread safe.
 *
 * @return result of the call
 */
NiFpga_Status NiFpga_Initialize(void);

/**
 * This must be called after all other function calls.
 *
 * @warning This function is not thread safe.
 *
 * @return result of the call
 */
NiFpga_Status NiFpga_Finalize(void);

/**
 * A handle to an FPGA session.
 */
typedef uint32_t NiFpga_Session;

/**
 * Attributes that NiFpga_Open accepts.
 */
typedef enum
{
   NiFpga_OpenAttribute_NoRun = 1
} NiFpga_OpenAttribute;

/**
 * Opens a session to the FPGA. This call will ensure that the contents of the
 * bitfile are programmed to the FPGA. The FPGA will be run unless the NoRun
 * attribute is used.
 *
 * Note that the correct signature must be passed to ensure that your
 * application was built with the correct generated header file for the bitfile
 * found on disk.
 *
 * On PharLap ETS systems, this path should be an absolute path starting with
 * "C:\\".
 *
 * @param bitfile path to the bitfile
 * @param signature signature of the bitfile
 * @param resource RIO resource string to open ("RIO0" or "rio://mysystem/RIO")
 * @param attribute bitwise OR of any NiFpga_OpenAttributes, or 0
 * @param session outputs the session handle, which must be closed when no
 *                longer needed
 * @return result of the call
 */
NiFpga_Status NiFpga_Open(const char*     bitfile,
                          const char*     signature,
                          const char*     resource,
                          uint32_t        attribute,
                          NiFpga_Session* session);

/**
 * Attributes that NiFpga_Close accepts.
 */
typedef enum
{
   NiFpga_CloseAttribute_NoResetIfLastSession = 1
} NiFpga_CloseAttribute;

/**
 * Closes the session to the FPGA. The FPGA will be reset unless either another
 * session is still open or the NoResetIfLastSession attribute is used.
 *
 * @param session handle to a currently open session
 * @param attribute bitwise OR of any NiFpga_CloseAttributes, or 0
 * @return result of the call
 */
NiFpga_Status NiFpga_Close(NiFpga_Session session,
                           uint32_t       attribute);

/**
 * Attributes that NiFpga_Run accepts.
 */
typedef enum
{
   NiFpga_RunAttribute_WaitUntilDone = 1
} NiFpga_RunAttribute;

/**
 * Runs the FPGA VI on the target. If WaitUntilDone is used, the FPGA will run
 * until it finishes executing (if ever).
 *
 * @param session handle to a currently open session
 * @param attribute bitwise OR of any NiFpga_RunAttributes, or 0
 * @return result of the call
 */
NiFpga_Status NiFpga_Run(NiFpga_Session session,
                         uint32_t       attribute);

/**
 * Aborts the FPGA VI.
 *
 * @param session handle to a currently open session
 * @return result of the call
 */
NiFpga_Status NiFpga_Abort(NiFpga_Session session);

/**
 * Resets the FPGA VI.
 *
 * @param session handle to a currently open session
 * @return result of the call
 */
NiFpga_Status NiFpga_Reset(NiFpga_Session session);

/**
 * Re-downloads the FPGA bitstream to the target.
 *
 * @param session handle to a currently open session
 * @return result of the call
 */
NiFpga_Status NiFpga_Download(NiFpga_Session session);

/**
 * Reads a boolean value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadBool(NiFpga_Session session,
                              uint32_t       indicator,
                              NiFpga_Bool*   value);

/**
 * Reads a signed 8-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadI8(NiFpga_Session session,
                            uint32_t       indicator,
                            int8_t*        value);

/**
 * Reads an unsigned 8-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadU8(NiFpga_Session session,
                            uint32_t       indicator,
                            uint8_t*       value);

/**
 * Reads a signed 16-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadI16(NiFpga_Session session,
                             uint32_t       indicator,
                             int16_t*       value);

/**
 * Reads an unsigned 16-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadU16(NiFpga_Session session,
                             uint32_t       indicator,
                             uint16_t*      value);

/**
 * Reads a signed 32-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadI32(NiFpga_Session session,
                             uint32_t       indicator,
                             int32_t*       value);

/**
 * Reads an unsigned 32-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadU32(NiFpga_Session session,
                             uint32_t       indicator,
                             uint32_t*      value);

/**
 * Reads a signed 64-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadI64(NiFpga_Session session,
                             uint32_t       indicator,
                             int64_t*       value);

/**
 * Reads an unsigned 64-bit integer value from a given indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param value outputs the value that was read
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadU64(NiFpga_Session session,
                             uint32_t       indicator,
                             uint64_t*      value);

/**
 * Writes a boolean value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteBool(NiFpga_Session session,
                               uint32_t       control,
                               NiFpga_Bool    value);

/**
 * Writes a signed 8-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteI8(NiFpga_Session session,
                             uint32_t       control,
                             int8_t         value);

/**
 * Writes an unsigned 8-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteU8(NiFpga_Session session,
                             uint32_t       control,
                             uint8_t        value);

/**
 * Writes a signed 16-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteI16(NiFpga_Session session,
                              uint32_t       control,
                              int16_t        value);

/**
 * Writes an unsigned 16-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteU16(NiFpga_Session session,
                              uint32_t       control,
                              uint16_t       value);

/**
 * Writes a signed 32-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteI32(NiFpga_Session session,
                              uint32_t       control,
                              int32_t        value);

/**
 * Writes an unsigned 32-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteU32(NiFpga_Session session,
                              uint32_t       control,
                              uint32_t       value);

/**
 * Writes a signed 64-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteI64(NiFpga_Session session,
                              uint32_t       control,
                              int64_t        value);

/**
 * Writes an unsigned 64-bit integer value to a given control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param value value to write
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteU64(NiFpga_Session session,
                              uint32_t       control,
                              uint64_t       value);

/**
 * Reads boolean values from a given array indicator or control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayBool(NiFpga_Session session,
                                   uint32_t       indicator,
                                   NiFpga_Bool*   values,
                                   uint32_t       size);

/**
 * Reads signed 8-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayI8(NiFpga_Session session,
                                 uint32_t       indicator,
                                 int8_t*        values,
                                 uint32_t       size);

/**
 * Reads unsigned 8-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayU8(NiFpga_Session session,
                                 uint32_t       indicator,
                                 uint8_t*       values,
                                 uint32_t       size);

/**
 * Reads signed 16-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayI16(NiFpga_Session session,
                                  uint32_t       indicator,
                                  int16_t*       values,
                                  uint32_t       size);

/**
 * Reads unsigned 16-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayU16(NiFpga_Session session,
                                  uint32_t       indicator,
                                  uint16_t*      values,
                                  uint32_t       size);

/**
 * Reads signed 32-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayI32(NiFpga_Session session,
                                  uint32_t       indicator,
                                  int32_t*       values,
                                  uint32_t       size);

/**
 * Reads unsigned 32-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayU32(NiFpga_Session session,
                                  uint32_t       indicator,
                                  uint32_t*      values,
                                  uint32_t       size);

/**
 * Reads signed 64-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayI64(NiFpga_Session session,
                                  uint32_t       indicator,
                                  int64_t*       values,
                                  uint32_t       size);

/**
 * Reads unsigned 64-bit integer values from a given array indicator or
 * control.
 *
 * @param session handle to a currently open session
 * @param indicator indicator/control from which to read
 * @param values outputs the values that were read
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadArrayU64(NiFpga_Session session,
                                  uint32_t       indicator,
                                  uint64_t*      values,
                                  uint32_t       size);

/**
 * Writes boolean values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayBool(NiFpga_Session     session,
                                    uint32_t           control,
                                    const NiFpga_Bool* values,
                                    uint32_t           size);

/**
 * Writes signed 8-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayI8(NiFpga_Session session,
                                  uint32_t       control,
                                  const int8_t*  values,
                                  uint32_t       size);

/**
 * Writes unsigned 8-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayU8(NiFpga_Session session,
                                  uint32_t       control,
                                  const uint8_t* values,
                                  uint32_t       size);

/**
 * Writes signed 16-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayI16(NiFpga_Session session,
                                   uint32_t       control,
                                   const int16_t* values,
                                   uint32_t       size);

/**
 * Writes unsigned 16-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayU16(NiFpga_Session  session,
                                   uint32_t        control,
                                   const uint16_t* values,
                                   uint32_t        size);

/**
 * Writes signed 32-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayI32(NiFpga_Session session,
                                   uint32_t       control,
                                   const int32_t* values,
                                   uint32_t       size);

/**
 * Writes unsigned 32-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayU32(NiFpga_Session  session,
                                   uint32_t        control,
                                   const uint32_t* values,
                                   uint32_t        size);

/**
 * Writes signed 64-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayI64(NiFpga_Session session,
                                   uint32_t       control,
                                   const int64_t* values,
                                   uint32_t       size);

/**
 * Writes unsigned 64-bit integer values to a given array control or indicator.
 *
 * @param session handle to a currently open session
 * @param control control/indicator to which to write
 * @param values values to write
 * @param size number of values in this array
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteArrayU64(NiFpga_Session  session,
                                   uint32_t        control,
                                   const uint64_t* values,
                                   uint32_t        size);

/**
 * Enumeration of all possible IRQs.
 */
typedef enum
{
   NiFpga_Irq_0  = 1 << 0,
   NiFpga_Irq_1  = 1 << 1,
   NiFpga_Irq_2  = 1 << 2,
   NiFpga_Irq_3  = 1 << 3,
   NiFpga_Irq_4  = 1 << 4,
   NiFpga_Irq_5  = 1 << 5,
   NiFpga_Irq_6  = 1 << 6,
   NiFpga_Irq_7  = 1 << 7,
   NiFpga_Irq_8  = 1 << 8,
   NiFpga_Irq_9  = 1 << 9,
   NiFpga_Irq_10 = 1 << 10,
   NiFpga_Irq_11 = 1 << 11,
   NiFpga_Irq_12 = 1 << 12,
   NiFpga_Irq_13 = 1 << 13,
   NiFpga_Irq_14 = 1 << 14,
   NiFpga_Irq_15 = 1 << 15,
   NiFpga_Irq_16 = 1 << 16,
   NiFpga_Irq_17 = 1 << 17,
   NiFpga_Irq_18 = 1 << 18,
   NiFpga_Irq_19 = 1 << 19,
   NiFpga_Irq_20 = 1 << 20,
   NiFpga_Irq_21 = 1 << 21,
   NiFpga_Irq_22 = 1 << 22,
   NiFpga_Irq_23 = 1 << 23,
   NiFpga_Irq_24 = 1 << 24,
   NiFpga_Irq_25 = 1 << 25,
   NiFpga_Irq_26 = 1 << 26,
   NiFpga_Irq_27 = 1 << 27,
   NiFpga_Irq_28 = 1 << 28,
   NiFpga_Irq_29 = 1 << 29,
   NiFpga_Irq_30 = 1 << 30,
   NiFpga_Irq_31 = 1 << 31
} NiFpga_Irq;

/**
 * Represents an infinite timeout.
 */
static const uint32_t NiFpga_Infinite = 0xFFFFFFFF;

/**
 * See NiFpga_ReserveIrqContext for more information.
 */
typedef void* NiFpga_IrqContext;

/**
 * IRQ contexts are single-threaded; Only one thread may be "waiting" on a
 * particular context at any given time. Clients must reserve as many contexts
 * as the application requires.
 *
 * If a context is successfully reserved (returned status is not fatal), the
 * context must be unreserved later. Otherwise, a memory leak will occur.
 *
 * @param session handle to a currently open session
 * @param context outputs the IRQ context
 * @return result of the call
 */
NiFpga_Status NiFpga_ReserveIrqContext(NiFpga_Session     session,
                                       NiFpga_IrqContext* context);

/**
 * Unreserves an IRQ context obtained from NiFpga_ReserveIrqContext.
 *
 * @param session handle to a currently open session
 * @param context IRQ context to unreserve
 * @return result of the call
 */
NiFpga_Status NiFpga_UnreserveIrqContext(NiFpga_Session    session,
                                         NiFpga_IrqContext context);

/**
 * Blocking call which stops the calling thread until the specified IRQs have
 * been asserted on the FPGA, or the timeout period expires. An IRQ context
 * must have been reserved earlier using NiFpga_ReserveIrqContext. The context
 * must not be in use by other threads at the time of this call.
 *
 * This call can be used to wait on a set of IRQs. If any IRQ in the set is
 * asserted by the FPGA, this call will return. The irqsAsserted parameter can
 * be used to determine which IRQs were asserted in this case.
 *
 * @param session handle to a currently open session
 * @param context IRQ context with which to wait
 * @param irqs bitwise OR of NiFpga_Irqs
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param irqsAsserted if non-NULL, outputs the set of IRQs that were asserted
 * @param timedOut if non-NULL, outputs whether the timeout expired
 * @return result of the call
 */
NiFpga_Status NiFpga_WaitOnIrqs(NiFpga_Session    session,
                                NiFpga_IrqContext context,
                                uint32_t          irqs,
                                uint32_t          timeout,
                                uint32_t*         irqsAsserted,
                                NiFpga_Bool*      timedOut);

/**
 * Acknowledges an IRQ or set of IRQs.
 *
 * @param session handle to a currently open session
 * @param irqs bitwise OR of NiFpga_Irqs
 * @return result of the call
 */
NiFpga_Status NiFpga_AcknowledgeIrqs(NiFpga_Session session,
                                     uint32_t       irqs);

/**
 * Configures the depth of a FIFO.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to configure
 * @param depth the number of elements deep the fifo is
 * @return result of the call
 */
NiFpga_Status NiFpga_ConfigureFifo(NiFpga_Session session,
                                   uint32_t       fifo,
                                   uint32_t       depth);

/**
 * Starts a FIFO.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to start
 * @return result of the call
 */
NiFpga_Status NiFpga_StartFifo(NiFpga_Session session,
                               uint32_t       fifo);

/**
 * Stops a FIFO.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to stop
 * @return result of the call
 */
NiFpga_Status NiFpga_StopFifo(NiFpga_Session session,
                              uint32_t       fifo);

/**
 * Reads from a FIFO of booleans.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoBool(NiFpga_Session session,
                                  uint32_t       fifo,
                                  NiFpga_Bool*   data,
                                  uint32_t       count,
                                  uint32_t       timeout,
                                  uint32_t*      remaining);

/**
 * Reads from a FIFO of signed 8-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoI8(NiFpga_Session session,
                                uint32_t       fifo,
                                int8_t*        data,
                                uint32_t       count,
                                uint32_t       timeout,
                                uint32_t*      remaining);

/**
 * Reads from a FIFO of unsigned 8-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoU8(NiFpga_Session session,
                                uint32_t       fifo,
                                uint8_t*       data,
                                uint32_t       count,
                                uint32_t       timeout,
                                uint32_t*      remaining);

/**
 * Reads from a FIFO of signed 16-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoI16(NiFpga_Session session,
                                 uint32_t       fifo,
                                 int16_t*       data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Reads from a FIFO of unsigned 16-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoU16(NiFpga_Session session,
                                 uint32_t       fifo,
                                 uint16_t*      data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Reads from a FIFO of signed 32-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoI32(NiFpga_Session session,
                                 uint32_t       fifo,
                                 int32_t*       data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Reads from a FIFO of unsigned 32-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoU32(NiFpga_Session session,
                                 uint32_t       fifo,
                                 uint32_t*      data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Reads from a FIFO of signed 64-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoI64(NiFpga_Session session,
                                 uint32_t       fifo,
                                 int64_t*       data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Reads from a FIFO of unsigned 64-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo from which to read
 * @param data outputs the data that was read
 * @param count number of elements to read
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_ReadFifoU64(NiFpga_Session session,
                                 uint32_t       fifo,
                                 uint64_t*      data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Writes to a FIFO of booleans.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoBool(NiFpga_Session     session,
                                   uint32_t           fifo,
                                   const NiFpga_Bool* data,
                                   uint32_t           count,
                                   uint32_t           timeout,
                                   uint32_t*          remaining);

/**
 * Writes to a FIFO of signed 8-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoI8(NiFpga_Session session,
                                 uint32_t       fifo,
                                 const int8_t*  data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Writes to a FIFO of unsigned 8-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoU8(NiFpga_Session session,
                                 uint32_t       fifo,
                                 const uint8_t* data,
                                 uint32_t       count,
                                 uint32_t       timeout,
                                 uint32_t*      remaining);

/**
 * Writes to a FIFO of signed 16-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoI16(NiFpga_Session session,
                                  uint32_t       fifo,
                                  const int16_t* data,
                                  uint32_t       count,
                                  uint32_t       timeout,
                                  uint32_t*      remaining);

/**
 * Writes to a FIFO of unsigned 16-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoU16(NiFpga_Session  session,
                                  uint32_t        fifo,
                                  const uint16_t* data,
                                  uint32_t        count,
                                  uint32_t        timeout,
                                  uint32_t*       remaining);

/**
 * Writes to a FIFO of signed 32-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoI32(NiFpga_Session session,
                                  uint32_t       fifo,
                                  const int32_t* data,
                                  uint32_t       count,
                                  uint32_t       timeout,
                                  uint32_t*      remaining);

/**
 * Writes to a FIFO of unsigned 32-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoU32(NiFpga_Session  session,
                                  uint32_t        fifo,
                                  const uint32_t* data,
                                  uint32_t        count,
                                  uint32_t        timeout,
                                  uint32_t*       remaining);

/**
 * Writes to a FIFO of signed 64-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoI64(NiFpga_Session session,
                                  uint32_t       fifo,
                                  const int64_t* data,
                                  uint32_t       count,
                                  uint32_t       timeout,
                                  uint32_t*      remaining);

/**
 * Writes to a FIFO of unsigned 64-bit integers.
 *
 * @param session handle to a currently open session
 * @param fifo the fifo to which to write
 * @param data data to write
 * @param count number of elements to write
 * @param timeout timeout in milliseconds, or NiFpga_Infinite
 * @param remaining if non-NULL, outputs the number of elements remaining
 * @return result of the call
 */
NiFpga_Status NiFpga_WriteFifoU64(NiFpga_Session  session,
                                  uint32_t        fifo,
                                  const uint64_t* data,
                                  uint32_t        count,
                                  uint32_t        timeout,
                                  uint32_t*       remaining);

#if NiFpga_Cpp
}
#endif

#endif
