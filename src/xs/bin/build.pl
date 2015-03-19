use strict;
use warnings;
use Template;
use Path::Class qw( file dir );

my $xs_root = file(__FILE__)->parent->parent->absolute;

my @impl = qw( ffcall libffi );

foreach my $impl (@impl)
{
  my $config = {
    INCLUDE_PATH => [ map { $_->stringify } ($xs_root->subdir('tmpl'), $xs_root->subdir($impl, 'tmpl')) ],
    ABSOLUTE     => 1,
    FILTERS      => {
      myindent4 => sub {
        my($package, $filename, $line) = caller;
        $line = 2;
        join "\n", map { /^#/ ? $_ : "    $_" } split /\n/, $_[0];
      },
    },
  };
  
  $config->{LOAD_TEMPLATES} = [ My::TemplateProvider->new($config) ];

  my $tt = Template->new($config);
  
  my $vars = {
    impl => $impl,
    loc => {
      filename => sub {
        my($package, $filename, $line) = caller;
        $filename;
      },
      line => sub {
        my($package, $filename, $line) = caller;
        $line;
      },
    },
  };
  
  my $from = $xs_root->file('tmpl','call.tt')->stringify;
  my $to   = $xs_root->file($impl, 'call.c') ->stringify;
  print "$from => $to\n";
  $tt->process($from, $vars, $to)
    || die $tt->error;
}

package
  My::TemplateProvider;

use File::stat;
use base qw( Template::Provider );

sub _template_content
{
  my($self, $path) = @_;
  
  return $self->SUPER::_template_content($path) unless -r $path;

  my $fh;
  open $fh, '<', $path;
  my @lines = <$fh>;
  close $fh;

  my $data = "\n";
  
  my $line = 1;
  my $dirty = 1;
  
  while(@lines)
  {
    $data .= "#line $line \"$path\"\n" if $dirty;
    my $line = shift @lines;
    $dirty = $line =~ /\[\%|\%\]|\%\%/;
    $data .= $line;
    $line++;
  }
  
  wantarray ? ($data, '', stat($path)->mtime) : $data;
}

