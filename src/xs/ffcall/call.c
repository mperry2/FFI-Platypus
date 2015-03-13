#include "ffi_platypus_c.h"
#include "ffi_platypus_xs.h"
#include "ffi_platypus_ffcall.h"

#line 5 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"

XS(ffi_pl_ffcall_sub_call_xsub)
{
  dVAR; dXSARGS;
  
  {
    ffi_pl_function *self;
    self = (ffi_pl_function*) CvXSUBANY(cv).any_ptr;
    
#line 2 "/home/ollisg/dev/FFI-Platypus/src/xs/ffcall/tmpl/dispatch.tt"
    
    {
      /* Dispatch ffcall */
    }

#line 18 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
  }
}

XS(ffi_pl_ffcall_sub_call_function)
{
  dVAR; dXSARGS;
  
  if(items < 1)
  {
    croak_xs_usage(cv, "self, ...");
  }
  else
  {
    ffi_pl_function *self;
    if(sv_isobject(ST(0)) && sv_derived_from(ST(0), "FFI::Platypus::ffcall::Function"))
      self = INT2PTR(ffi_pl_function *, SvIV((SV*) SvRV(ST(0))));
    else
      croak("self is not of type FFI::Platypus::::Function");
    
#line 2 "/home/ollisg/dev/FFI-Platypus/src/xs/ffcall/tmpl/dispatch.tt"
    
    {
      /* Dispatch ffcall */
    }

#line 41 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
  }
}
