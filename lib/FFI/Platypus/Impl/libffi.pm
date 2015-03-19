package FFI::Platypus::Impl::libffi;

use strict;
use warnings;
use Carp qw( croak );
use base qw( FFI::Platypus );

sub function
{
  my($self, $name, $args, $ret) = @_;
  croak "usage \$ffi->function( name, [ arguments ], return_type)" unless @_ == 4;
  my @args = map { $self->_type_lookup($_) || croak "unknown type: $_" } @$args;
  $ret = $self->_type_lookup($ret) || croak "unknown type: $ret";
  my $address = $name =~ /^-?[0-9]+$/ ? $name : $self->find_symbol($name);
  croak "unable to find $name" unless defined $address || $self->ignore_not_found;
  return unless defined $address;
  
  #foreach my $type ($ret, @args)
  #{
  #  my $h = $type->meta;
  #  use YAML ();
  #  print YAML::Dump($h);
  #}
  
  FFI::Platypus::Function->new($self, $address, $self->{abi}, $ret, @args);
}

1;
