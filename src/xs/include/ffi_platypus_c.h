#ifndef FFI_PLATYPUS_C_H
#define FFI_PLATYPUS_C_H

#include "ffi_platypus_config.h"
#include "ffi_platypus_probe.h"

#ifdef HAVE_DLFCN_H
#ifndef PERL_OS_WINDOWS
#include <dlfcn.h>
#endif
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#ifdef HAVE_COMPLEX_H
#include <complex.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define FFI_PL_CUSTOM     0x1 /* FIXME */
#define FFI_PL_SHAPE_MASK 0x2 /* FIXME */
#define FFI_PL_SCALAR     0x3 /* FIXME */
#define FFI_PL_POINTER    0x4 /* FIXME */
#define FFI_PL_ARRAY      0x5 /* FIXME */

typedef struct {
  unsigned int platypus_type;
  unsigned int array_size;
  size_t unit_size;
  void *custom;
} ffi_pl_function_arg_or_ret_type;

typedef struct {
  unsigned int nargs;
  ffi_pl_function_arg_or_ret_type ret;
  ffi_pl_function_arg_or_ret_type args[0];
} ffi_pl_function;

typedef struct {
  void        *pointer;
  const char  *string;
  int8_t       sint8;
  uint8_t      uint8;
  int16_t      sint16;
  uint16_t     uint16;
  int32_t      sint32;
  uint32_t     uint32;
  int64_t      sint64;
  uint64_t     uint64;
  float        xfloat;
  double       xdouble;
} ffi_pl_argument;

typedef struct {
  int count;
  int reserved;
  ffi_pl_argument slot[0];
} ffi_pl_arguments;

extern ffi_pl_arguments *current_argv;

#ifdef __cplusplus
}
#endif


#endif
