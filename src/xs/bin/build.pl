use strict;
use warnings;
use Template;
use Path::Class qw( file dir );

my $xs_root = file(__FILE__)->parent->parent->absolute;

my @impl = qw( ffcall libffi );

foreach my $impl (@impl)
{
  my $tt = Template->new({
    INCLUDE_PATH => [ map { $_->stringify } ($xs_root->subdir('tmpl'), $xs_root->subdir($impl, 'tmpl')) ],
    ABSOLUTE     => 1,
    FILTERS      => {
      myindent4 => sub {
        my($package, $filename, $line) = caller;
        $line = 2;
        join "\n", "#line $line \"$filename\"", map { /^#/ ? $_ : "    $_" } split /\n/, $_[0];
      },
    },
  });
  
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
