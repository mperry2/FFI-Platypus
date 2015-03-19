
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
#include "ffi_platypus_c.h"
#include "ffi_platypus_xs.h"
#include "ffi_platypus_ffcall.h"
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"

XS(ffi_pl_ffcall_sub_call_xsub)
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
{
  dVAR; dXSARGS;
  
  {
    ffi_pl_function *self;
    self = (ffi_pl_function*) CvXSUBANY(cv).any_ptr;
    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/ffcall/tmpl/dispatch.tt"

    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/ffcall/tmpl/dispatch.tt"
    {
      /* Dispatch ffcall */
    }

#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
  }
}

XS(ffi_pl_ffcall__Function__call)
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
{
  dVAR; dXSARGS;
  
  if(items < 1)
  {
    croak_xs_usage(cv, "self, ...");
  }
  else
  {
    ffi_pl_function *self;
    if(sv_isobject(ST(0)) && sv_derived_from(ST(0), "FFI::Platypus::Impl::ffcall::Function"))
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
      self = INT2PTR(ffi_pl_function *, SvIV((SV*) SvRV(ST(0))));
    else
      croak("self is not of type FFI::Platypus::Impl::ffcall::Function");
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/ffcall/tmpl/dispatch.tt"

    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/ffcall/tmpl/dispatch.tt"
    {
      /* Dispatch ffcall */
    }

#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
  }
}
