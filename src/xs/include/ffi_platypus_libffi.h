#ifndef FFI_PLATYPUS_LIBFFI_H
#define FFI_PLATYPUS_LIBFFI_H

#include <ffi.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  SV *argument_in;
  SV *argument_out;
  unsigned int nargs;
} ffi_pl_argument_libffi_custom;

#ifdef __cplusplus
}
#endif


#endif
