#ifndef FFI_PLATYPUS_XS_H
#define FFI_PLATYPUS_XS_H

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "ppport.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#define Newx_or_alloca(ptr, count, type) ptr = _alloca(sizeof(type)*count)
#define Safefree_or_alloca(ptr) 
#define HAVE_ALLOCA 1
#elif defined(HAVE_ALLOCA)
#define Newx_or_alloca(ptr, count, type) ptr = alloca(sizeof(type)*count)
#define Safefree_or_alloca(ptr) 
#else
#define Newx_or_alloca(ptr, count, type) Newx(ptr, count, type)
#define Safefree_or_alloca(ptr) Safefree(ptr)
#endif

SV*  ffi_pl_custom_perl(SV*,SV*,int);

#ifdef __cplusplus
}
#endif

#endif
