
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
#include "ffi_platypus_c.h"
#include "ffi_platypus_xs.h"
#include "ffi_platypus_libffi.h"
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"

XS(ffi_pl_libffi_sub_call_xsub)
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
{
  dVAR; dXSARGS;
  
  {
    ffi_pl_function *self;
    self = (ffi_pl_function*) CvXSUBANY(cv).any_ptr;
    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/libffi/tmpl/dispatch.tt"

    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/libffi/tmpl/dispatch.tt"
    {
      const char *buffer;
      size_t buffer_size;
      ffi_pl_arguments *arguments;
      int perl_index;
      void **argument_pointers;
      
      buffer_size = sizeof(ffi_pl_argument) * self->nargs +
                    sizeof(void*) * self->nargs +
                    sizeof(ffi_pl_arguments);
      Newx_or_alloca(buffer, buffer_size, char);
      current_argv = arguments = (ffi_pl_arguments*) buffer;
      
      arguments->count = self->nargs;
      argument_pointers = (void**) &arguments->slot[arguments->count];
      
      /*
       * ARGUMENT IN
       */
      {
        int c_index;
        
        for(c_index=0, perl_index=0; c_index < self->nargs; c_index++, perl_index++)
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/libffi/tmpl/dispatch.tt"
        {
          SV *sv = ST(perl_index);
          
          if(self->args[perl_index].platypus_type & FFI_PL_CUSTOM)
          {
            sv = ffi_pl_custom_perl(((ffi_pl_argument_libffi_custom*)self->args[perl_index].custom)->argument_in, sv, c_index);
            if(sv == NULL)
              continue;
          }
          
          switch(self->args[perl_index].platypus_type & FFI_PL_SHAPE_MASK)
          {
            case FFI_PL_SCALAR:
              break;
            case FFI_PL_POINTER:
              break;
            case FFI_PL_ARRAY:
              break;
          }
        }
      }
      
    }

#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
  }
}

XS(ffi_pl_libffi_sub_call_function)
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
    if(sv_isobject(ST(0)) && sv_derived_from(ST(0), "FFI::Platypus::libffi::Function"))
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
      self = INT2PTR(ffi_pl_function *, SvIV((SV*) SvRV(ST(0))));
    else
      croak("self is not of type FFI::Platypus::::Function");
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/libffi/tmpl/dispatch.tt"

    
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/libffi/tmpl/dispatch.tt"
    {
      const char *buffer;
      size_t buffer_size;
      ffi_pl_arguments *arguments;
      int perl_index;
      void **argument_pointers;
      
      buffer_size = sizeof(ffi_pl_argument) * self->nargs +
                    sizeof(void*) * self->nargs +
                    sizeof(ffi_pl_arguments);
      Newx_or_alloca(buffer, buffer_size, char);
      current_argv = arguments = (ffi_pl_arguments*) buffer;
      
      arguments->count = self->nargs;
      argument_pointers = (void**) &arguments->slot[arguments->count];
      
      /*
       * ARGUMENT IN
       */
      {
        int c_index;
        
        for(c_index=0, perl_index=1; c_index < self->nargs; c_index++, perl_index++)
#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/libffi/tmpl/dispatch.tt"
        {
          SV *sv = ST(perl_index);
          
          if(self->args[perl_index].platypus_type & FFI_PL_CUSTOM)
          {
            sv = ffi_pl_custom_perl(((ffi_pl_argument_libffi_custom*)self->args[perl_index].custom)->argument_in, sv, c_index);
            if(sv == NULL)
              continue;
          }
          
          switch(self->args[perl_index].platypus_type & FFI_PL_SHAPE_MASK)
          {
            case FFI_PL_SCALAR:
              break;
            case FFI_PL_POINTER:
              break;
            case FFI_PL_ARRAY:
              break;
          }
        }
      }
      
    }

#line 1 "/home/ollisg/dev/FFI-Platypus/src/xs/tmpl/call.tt"
  }
}
