my $verbose = 0;
my %verbose_messages = ();
my %verbose_emitted = ();
my $user_codespellfile = "";
my $docsfile = "$D/../Documentation/dev-tools/checkpatch.rst";
my %maybe_linker_symbol; # for externs in c exceptions, when seen in *vmlinux.lds.h

  -v, --verbose              verbose mode
                             (default:$codespellfile)
	my %types = ();
	while ($text =~ /(?:(\bCHK|\bWARN|\bERROR|&\{\$msg_level})\s*\(|\$msg_type\s*=)\s*"([^"]+)"/g) {
		if (defined($1)) {
			if (exists($types{$2})) {
				$types{$2} .= ",$1" if ($types{$2} ne $1);
			} else {
				$types{$2} = $1;
			}
		} else {
			$types{$2} = "UNDETERMINED";
		}

	if ($color) {
		print(" ( Color coding: ");
		print(RED . "ERROR" . RESET);
		print(" | ");
		print(YELLOW . "WARNING" . RESET);
		print(" | ");
		print(GREEN . "CHECK" . RESET);
		print(" | ");
		print("Multiple levels / Undetermined");
		print(" )\n\n");
	}

	foreach my $type (sort keys %types) {
		my $orig_type = $type;
		if ($color) {
			my $level = $types{$type};
			if ($level eq "ERROR") {
				$type = RED . $type . RESET;
			} elsif ($level eq "WARN") {
				$type = YELLOW . $type . RESET;
			} elsif ($level eq "CHK") {
				$type = GREEN . $type . RESET;
			}
		}
		if ($verbose && exists($verbose_messages{$orig_type})) {
			my $message = $verbose_messages{$orig_type};
			$message =~ s/\n/\n\t/g;
			print("\t" . $message . "\n\n");
		}
sub load_docs {
	open(my $docs, '<', "$docsfile")
	    or warn "$P: Can't read the documentation file $docsfile $!\n";

	my $type = '';
	my $desc = '';
	my $in_desc = 0;

	while (<$docs>) {
		chomp;
		my $line = $_;
		$line =~ s/\s+$//;

		if ($line =~ /^\s*\*\*(.+)\*\*$/) {
			if ($desc ne '') {
				$verbose_messages{$type} = trim($desc);
			}
			$type = $1;
			$desc = '';
			$in_desc = 1;
		} elsif ($in_desc) {
			if ($line =~ /^(?:\s{4,}|$)/) {
				$line =~ s/^\s{4}//;
				$desc .= $line;
				$desc .= "\n";
			} else {
				$verbose_messages{$type} = trim($desc);
				$type = '';
				$desc = '';
				$in_desc = 0;
			}
		}
	}

	if ($desc ne '') {
		$verbose_messages{$type} = trim($desc);
	}
	close($docs);
}

	'v|verbose!'	=> \$verbose,
	'codespellfile=s'	=> \$user_codespellfile,
) or $help = 2;

if ($user_codespellfile) {
	# Use the user provided codespell file unconditionally
	$codespellfile = $user_codespellfile;
} elsif (!(-f $codespellfile)) {
	# If /usr/share/codespell/dictionary.txt is not present, try to find it
	# under codespell's install directory: <codespell_root>/data/dictionary.txt
	if (($codespell || $help) && which("python3") ne "") {
		my $python_codespell_dict = << "EOF";

import os.path as op
import codespell_lib
codespell_dir = op.dirname(codespell_lib.__file__)
codespell_file = op.join(codespell_dir, 'data', 'dictionary.txt')
print(codespell_file, end='')
EOF

		my $codespell_dict = `python3 -c "$python_codespell_dict" 2> /dev/null`;
		$codespellfile = $codespell_dict if (-f $codespell_dict);
	}
}

# $help is 1 if either -h, --help or --version is passed as option - exitcode: 0
# $help is 2 if invalid option is passed - exitcode: 1
help($help - 1) if ($help);
die "$P: --git cannot be used with --file or --fix\n" if ($git && ($file || $fix));
die "$P: --verbose cannot be used with --terse\n" if ($verbose && $terse);
if ($color =~ /^[01]$/) {
	$color = !$color;
} elsif ($color =~ /^always$/i) {
	$color = 1;
} elsif ($color =~ /^never$/i) {
	$color = 0;
} elsif ($color =~ /^auto$/i) {
	$color = (-t STDOUT);
} else {
	die "$P: Invalid color mode: $color\n";
}

load_docs() if ($verbose);
			__aligned\s*\(.*\)|
			__weak|
			__alloc_size\s*\(\s*\d+\s*(?:,\s*\d+\s*)?\)
our $String	= qr{(?:\b[Lu])?"[X\t]*"};
our $typeStdioTypedefs = qr{(?x:
	FILE
)};
	$typeKernelTypedefs\b|
	$typeStdioTypedefs\b
our @link_tags = qw(Link Closes);

#Create a search and print patterns for all these strings to be used directly below
our $link_tags_search = "";
our $link_tags_print = "";
foreach my $entry (@link_tags) {
	if ($link_tags_search ne "") {
		$link_tags_search .= '|';
		$link_tags_print .= ' or ';
	}
	$entry .= ':';
	$link_tags_search .= $entry;
	$link_tags_print .= "'$entry'";
}
$link_tags_search = "(?:${link_tags_search})";

our $obsolete_archives = qr{(?xi:
	\Qfreedesktop.org/archives/dri-devel\E |
	\Qlists.infradead.org\E |
	\Qlkml.org\E |
	\Qmail-archive.com\E |
	\Qmailman.alsa-project.org/pipermail\E |
	\Qmarc.info\E |
	\Qozlabs.org/pipermail\E |
	\Qspinics.net\E
)};

	"kmap"					=> "kmap_local_page",
	"kunmap"				=> "kunmap_local",
	"kmap_atomic"				=> "kmap_local_page",
	"kunmap_atomic"				=> "kunmap_local",
	(?:SKCIPHER_REQUEST|SHASH_DESC|AHASH_REQUEST)_ON_STACK\s*\(|
	(?:$Storage\s+)?(?:XA_STATE|XA_STATE_ORDER)\s*\(
	return 1 if (!$tree || which("python3") eq "" || !(-x "$root/scripts/spdxcheck.py") || !(-e "$gitroot"));
	my $status = `cd "$root_path"; echo "$license" | scripts/spdxcheck.py -`;
	} elsif ($lines[0] =~ /^fatal: ambiguous argument '$commit': unknown revision or path not in the working tree\./ ||
		 $lines[0] =~ /^fatal: bad object $commit/) {

	if ($terse) {
		$output = (split('\n', $output))[0] . "\n";
	}

	if ($verbose && exists($verbose_messages{$type}) &&
	    !exists($verbose_emitted{$type})) {
		$output .= $verbose_messages{$type} . "\n\n";
		$verbose_emitted{$type} = 1;
	}
	my $last_git_commit_id_linenr = -1;

					if (lc $email_address eq lc $author_address && $email_name eq $author_name) {
					} elsif (lc $email_address eq lc $author_address) {
					      "Co-developed-by: should not be used to attribute nominal patch author '$author'\n" . $herecurr);
					     "Co-developed-by: must be immediately followed by Signed-off-by:\n" . $herecurr);
				} elsif ($rawlines[$linenr] !~ /^signed-off-by:\s*(.*)/i) {
					     "Co-developed-by: must be immediately followed by Signed-off-by:\n" . $herecurr . $rawlines[$linenr] . "\n");
					     "Co-developed-by and Signed-off-by: name/email do not match\n" . $herecurr . $rawlines[$linenr] . "\n");
				}
			}

# check if Reported-by: is followed by a Closes: tag
			if ($sign_off =~ /^reported(?:|-and-tested)-by:$/i) {
				if (!defined $lines[$linenr]) {
					WARN("BAD_REPORTED_BY_LINK",
					     "Reported-by: should be immediately followed by Closes: with a URL to the report\n" . $herecurr . "\n");
				} elsif ($rawlines[$linenr] !~ /^closes:\s*/i) {
					WARN("BAD_REPORTED_BY_LINK",
					     "Reported-by: should be immediately followed by Closes: with a URL to the report\n" . $herecurr . $rawlines[$linenr] . "\n");
				}
			}
		}


# Check Fixes: styles is correct
		if (!$in_header_lines &&
		    $line =~ /^\s*fixes:?\s*(?:commit\s*)?[0-9a-f]{5,}\b/i) {
			my $orig_commit = "";
			my $id = "0123456789ab";
			my $title = "commit title";
			my $tag_case = 1;
			my $tag_space = 1;
			my $id_length = 1;
			my $id_case = 1;
			my $title_has_quotes = 0;

			if ($line =~ /(\s*fixes:?)\s+([0-9a-f]{5,})\s+($balanced_parens)/i) {
				my $tag = $1;
				$orig_commit = $2;
				$title = $3;

				$tag_case = 0 if $tag eq "Fixes:";
				$tag_space = 0 if ($line =~ /^fixes:? [0-9a-f]{5,} ($balanced_parens)/i);

				$id_length = 0 if ($orig_commit =~ /^[0-9a-f]{12}$/i);
				$id_case = 0 if ($orig_commit !~ /[A-F]/);

				# Always strip leading/trailing parens then double quotes if existing
				$title = substr($title, 1, -1);
				if ($title =~ /^".*"$/) {
					$title = substr($title, 1, -1);
					$title_has_quotes = 1;
				}
			}

			my ($cid, $ctitle) = git_commit_info($orig_commit, $id,
							     $title);

			if ($ctitle ne $title || $tag_case || $tag_space ||
			    $id_length || $id_case || !$title_has_quotes) {
				if (WARN("BAD_FIXES_TAG",
				     "Please use correct Fixes: style 'Fixes: <12 chars of sha1> (\"<title line>\")' - ie: 'Fixes: $cid (\"$ctitle\")'\n" . $herecurr) &&
				    $fix) {
					$fixed[$fixlinenr] = "Fixes: $cid (\"$ctitle\")";
		      $line =~ /^\s*(?:[\w\.\-\+]*\/)++[\w\.\-\+]+:/ ||
		      $line =~ /^\s*(?:Fixes:|$link_tags_search|$signature_tags)/i ||
					# A Fixes:, link or signature tag line
			     "Prefer a maximum 75 chars per line (possible unwrapped commit description?)\n" . $herecurr);
# Check for odd tags before a URI/URL
		if ($in_commit_log &&
		    $line =~ /^\s*(\w+:)\s*http/ && $1 !~ /^$link_tags_search$/) {
			if ($1 =~ /^v(?:ersion)?\d+/i) {
				WARN("COMMIT_LOG_VERSIONING",
				     "Patch version information should be after the --- line\n" . $herecurr);
			} else {
				WARN("COMMIT_LOG_USE_LINK",
				     "Unknown link reference '$1', use $link_tags_print instead\n" . $herecurr);
			}
		}

# Check for misuse of the link tags
		if ($in_commit_log &&
		    $line =~ /^\s*(\w+:)\s*(\S+)/) {
			my $tag = $1;
			my $value = $2;
			if ($tag =~ /^$link_tags_search$/ && $value !~ m{^https?://}) {
				WARN("COMMIT_LOG_WRONG_LINK",
				     "'$tag' should be followed by a public http(s) link\n" . $herecurr);
			}
		}

# A correctly formed commit description is:
#    commit <SHA-1 hash length 12+ chars> ("Complete commit subject")
# with the commit subject '("' prefix and '")' suffix
# This is a fairly compilicated block as it tests for what appears to be
# bare SHA-1 hash with  minimum length of 5.  It also avoids several types of
# possible SHA-1 matches.
# A commit match can span multiple lines so this block attempts to find a
# complete typical commit on a maximum of 3 lines
		if ($perl_version_ok &&
		    $in_commit_log && !$commit_log_possible_stack_dump &&
		    (($line =~ /\bcommit\s+[0-9a-f]{5,}\b/i ||
		      ($line =~ /\bcommit\s*$/i && defined($rawlines[$linenr]) && $rawlines[$linenr] =~ /^\s*[0-9a-f]{5,}\b/i)) ||
			my $herectx = $herecurr;
			my $has_parens = 0;
			my $has_quotes = 0;

			my $input = $line;
			if ($line =~ /(?:\bcommit\s+[0-9a-f]{5,}|\bcommit\s*$)/i) {
				for (my $n = 0; $n < 2; $n++) {
					if ($input =~ /\bcommit\s+[0-9a-f]{5,}\s*($balanced_parens)/i) {
						$orig_desc = $1;
						$has_parens = 1;
						# Always strip leading/trailing parens then double quotes if existing
						$orig_desc = substr($orig_desc, 1, -1);
						if ($orig_desc =~ /^".*"$/) {
							$orig_desc = substr($orig_desc, 1, -1);
							$has_quotes = 1;
						}
						last;
					}
					last if ($#lines < $linenr + $n);
					$input .= " " . trim($rawlines[$linenr + $n]);
					$herectx .= "$rawlines[$linenr + $n]\n";
				}
				$herectx = $herecurr if (!$has_parens);
			}
			if ($input =~ /\b(c)ommit\s+([0-9a-f]{5,})\b/i) {
				$short = 0 if ($input =~ /\bcommit\s+[0-9a-f]{12,40}/i);
				$long = 1 if ($input =~ /\bcommit\s+[0-9a-f]{41,}/i);
				$space = 0 if ($input =~ /\bcommit [0-9a-f]/i);
				$case = 0 if ($input =~ /\b[Cc]ommit\s+[0-9a-f]{5,40}[^A-F]/);
			} elsif ($input =~ /\b([0-9a-f]{12,40})\b/i) {
			    ($short || $long || $space || $case || ($orig_desc ne $description) || !$has_quotes) &&
			    $last_git_commit_id_linenr != $linenr - 1) {
				      "Please use git commit description style 'commit <12+ chars of sha1> (\"<title line>\")' - ie: '${init_char}ommit $id (\"$description\")'\n" . $herectx);
			#don't report the next line if this line ends in commit and the sha1 hash is the next line
			$last_git_commit_id_linenr = $linenr if ($line =~ /\bcommit\s*$/i);
		}

# Check for mailing list archives other than lore.kernel.org
		if ($rawline =~ m{http.*\b$obsolete_archives}) {
			WARN("PREFER_LORE_ARCHIVE",
			     "Use lore.kernel.org archive links when possible - see https://lore.kernel.org/lists.html\n" . $herecurr);
			     "DT bindings should be in DT schema format. See: Documentation/devicetree/bindings/writing-schema.rst\n");
			my $ln = $linenr;
			my $needs_help = 0;
			my $has_help = 0;
			my $help_length = 0;
			while (defined $lines[$ln]) {
				my $f = $lines[$ln++];
				last if ($f !~ /^[\+ ]/);	# !patch context
				if ($f =~ /^\+\s*(?:bool|tristate|prompt)\s*["']/) {
					$needs_help = 1;
					next;
				}
				if ($f =~ /^\+\s*help\s*$/) {
					$has_help = 1;
					next;
				$f =~ s/^.//;	# strip patch context [+ ]
				$f =~ s/#.*//;	# strip # directives
				$f =~ s/^\s+//;	# strip leading blanks
				next if ($f =~ /^$/);	# skip blank lines
				# At the end of this Kconfig block:
				if ($f =~ /^(?:config|menuconfig|choice|endchoice|
					       if|endif|menu|endmenu|source)\b/x) {
				$help_length++ if ($has_help);
			if ($needs_help &&
			    $help_length < $min_conf_desc_length) {
				my $stat_real = get_stat_real($linenr, $ln - 1);
				     "please write a help paragraph that fully describes the config symbol\n" . "$here\n$stat_real\n");
				} elsif ($realfile =~ /\.(c|rs|dts|dtsi)$/) {
					    $spdx_license !~ /GPL-2\.0(?:-only)? OR BSD-2-Clause/) {
					if ($realfile =~ m@^include/dt-bindings/@ &&
					    $spdx_license !~ /GPL-2\.0(?:-only)? OR \S+/) {
						WARN("SPDX_LICENSE_TAG",
						     "DT binding headers should be licensed (GPL-2.0-only OR .*)\n" . $herecurr);
					}
		if ($rawline =~ /^\+.*\b\Q$realfile\E\b/) {
		next if ($realfile !~ /\.(h|c|rs|s|S|sh|dtsi|dts)$/);
			     "Avoid using '.L' prefixed local symbol names for denoting a range of code via 'SYM_*_START/END' annotations; see Documentation/core-api/asm-annotations.rst\n" . $herecurr);
		      $line =~ /^\+\s*(?:EXPORT_SYMBOL|early_param|ALLOW_ERROR_INJECTION)/ ||
			$name =~ s/^\s*($Ident).*/$1/;
# do not use BUG() or variants
		if ($line =~ /\b(?!AA_|BUILD_|DCCP_|IDA_|KVM_|RWLOCK_|snd_|SPIN_)(?:[a-zA-Z_]*_)?BUG(?:_ON)?(?:_[A-Z_]+)?\s*\(/) {
				      "Do not crash the kernel unless it is absolutely unavoidable--use WARN_ON_ONCE() plus recovery code (if feasible) instead of BUG() or variants\n" . $herecurr);
				asm|__asm__|scoped_guard)$/x)
# check that goto labels aren't indented (allow a single space indentation)
# and ignore bitfield definitions like foo:1
# Strictly, labels can have whitespace after the identifier and before the :
# but this is not allowed here as many ?: uses would appear to be labels
		if ($sline =~ /^.\s+[A-Za-z_][A-Za-z\d_]*:(?!\s*\d+)/ &&
		    $sline !~ /^. [A-Za-z\d_][A-Za-z\d_]*:/ &&
		    $sline !~ /^.\s+default:/) {
			if ($name ne 'EOF' && $name ne 'ERROR' && $name !~ /^EPOLL/) {
			my $fixed_assign_in_if = 0;
						$fixed_assign_in_if = 1;
				if (ERROR("TRAILING_STATEMENTS",
					  "trailing statements should be on next line\n" . $herecurr . $stat_real) &&
				    !$fixed_assign_in_if &&
				    $cond_lines == 0 &&
				    $fix && $perl_version_ok &&
				    $fixed[$fixlinenr] =~ /^\+(\s*)((?:if|while|for)\s*$balanced_parens)\s*(.*)$/) {
					my $indent = $1;
					my $test = $2;
					my $rest = rtrim($4);
					if ($rest =~ /;$/) {
						$fixed[$fixlinenr] = "\+$indent$test";
						fix_insert_line($fixlinenr + 1, "$indent\t$rest");
					}
				}
#Ignore ETHTOOL_LINK_MODE_<foo> variants
			    $var !~ /^ETHTOOL_LINK_MODE_/ &&
				while ($var =~ m{\b($Ident)}g) {
			    $dstat !~ /^case\b/ &&					# case ...
				$tmp_stmt =~ s/\b(__must_be_array|offsetof|sizeof|sizeof_field|__stringify|typeof|__typeof__|__builtin\w+|typecheck\s*\(\s*$Type\s*,|\#+)\s*\(*\s*$arg\s*\)*\b//g;
		} elsif ($realfile =~ m@/vmlinux.lds.h$@) {
		    $line =~ s/(\w+)/$maybe_linker_symbol{$1}++/ge;
		    #print "REAL: $realfile\nln: $line\nkeys:", sort keys %maybe_linker_symbol;
		if ($line =~ /$String[A-Z_]/ ||
		    ($line =~ /([A-Za-z0-9_]+)$String/ && $1 !~ /^[Lu]$/)) {
		if ($line =~ /$String\s*[Lu]?"/) {
					if ($extension !~ /[4SsBKRraEehMmIiUDdgVCbGNOxtf]/ ||
					     defined $qualifier && $qualifier !~ /^w/) ||
					    ($extension eq "4" &&
					     defined $qualifier && $qualifier !~ /^cc/)) {
					my $msg_level = \&WARN;
					} elsif ($bad_specifier =~ /pA/) {
						$use =  " - '%pA' is only intended to be used from Rust code";
						$msg_level = \&ERROR;
					&{$msg_level}("VSPRINTF_POINTER_EXTENSION",
						      "$ext_type vsprintf pointer extension '$bad_specifier'$use\n" . "$here\n$stat_real\n");
# strcpy uses that should likely be strscpy
		if ($line =~ /\bstrcpy\s*\(/) {
			WARN("STRCPY",
			     "Prefer strscpy over strcpy - see: https://github.com/KSPP/linux/issues/88\n" . $herecurr);
		}

			     "Prefer strscpy over strlcpy - see: https://github.com/KSPP/linux/issues/89\n" . $herecurr);
		}

# strncpy uses that should likely be strscpy or strscpy_pad
		if ($line =~ /\bstrncpy\s*\(/) {
			WARN("STRNCPY",
			     "Prefer strscpy, strscpy_pad, or __nonstring over strncpy - see: https://github.com/KSPP/linux/issues/90\n" . $herecurr);
		}

# ethtool_sprintf uses that should likely be ethtool_puts
		if ($line =~ /\bethtool_sprintf\s*\(\s*$FuncArg\s*,\s*$FuncArg\s*\)/) {
			if (WARN("PREFER_ETHTOOL_PUTS",
				 "Prefer ethtool_puts over ethtool_sprintf with only two arguments\n" . $herecurr) &&
			    $fix) {
				$fixed[$fixlinenr] =~ s/\bethtool_sprintf\s*\(\s*($FuncArg)\s*,\s*($FuncArg)/ethtool_puts($1, $7)/;
			}
		# use $rawline because $line loses %s via sanitization and thus we can't match against it.
		if ($rawline =~ /\bethtool_sprintf\s*\(\s*$FuncArg\s*,\s*\"\%s\"\s*,\s*$FuncArg\s*\)/) {
			if (WARN("PREFER_ETHTOOL_PUTS",
				 "Prefer ethtool_puts over ethtool_sprintf with standalone \"%s\" specifier\n" . $herecurr) &&
			    $fix) {
				$fixed[$fixlinenr] =~ s/\bethtool_sprintf\s*\(\s*($FuncArg)\s*,\s*"\%s"\s*,\s*($FuncArg)/ethtool_puts($1, $7)/;
			}
		}


		} elsif ($realfile =~ /\.c$/ && defined $stat &&
		    $stat =~ /^\+extern struct\s+(\w+)\s+(\w+)\[\];/)
		{
			my ($st_type, $st_name) = ($1, $2);

			for my $s (keys %maybe_linker_symbol) {
			    #print "Linker symbol? $st_name : $s\n";
			    goto LIKELY_LINKER_SYMBOL
				if $st_name =~ /$s/;
			}
			WARN("AVOID_EXTERNS",
			     "found a file-scoped extern type:$st_type name:$st_name in .c file\n"
			     . "is this a linker symbol ?\n" . $herecurr);
		  LIKELY_LINKER_SYMBOL:

# check for (kv|k)[mz]alloc with multiplies that could be kmalloc_array/kvmalloc_array/kvcalloc/kcalloc
		    $stat =~ /^\+\s*($Lval)\s*\=\s*(?:$balanced_parens)?\s*((?:kv|k)[mz]alloc)\s*\(\s*($FuncArg)\s*\*\s*($FuncArg)\s*,/) {
			$newfunc = "kvmalloc_array" if ($oldfunc eq "kvmalloc");
			$newfunc = "kvcalloc" if ($oldfunc eq "kvzalloc");
					$fixed[$fixlinenr] =~ s/\b($Lval)\s*\=\s*(?:$balanced_parens)?\s*((?:kv|k)[mz]alloc)\s*\(\s*($FuncArg)\s*\*\s*($FuncArg)/$1 . ' = ' . "$newfunc(" . trim($r1) . ', ' . trim($r2)/e;
		if ($line =~ /\b((?:devm_)?((?:k|kv)?(calloc|malloc_array)(?:_node)?))\s*\(\s*sizeof\b/) {
# return sysfs_emit(foo, fmt, ...) fmt without newline
		if ($line =~ /\breturn\s+sysfs_emit\s*\(\s*$FuncArg\s*,\s*($String)/ &&
		    substr($rawline, $-[6], $+[6] - $-[6]) !~ /\\n"$/) {
			my $offset = $+[6] - 1;
			if (WARN("SYSFS_EMIT",
				 "return sysfs_emit(...) formats should include a terminating newline\n" . $herecurr) &&
			    $fix) {
				substr($fixed[$fixlinenr], $offset, 0) = '\\n';
			}
		}

# check for array definition/declarations that should use flexible arrays instead
		if ($sline =~ /^[\+ ]\s*\}(?:\s*__packed)?\s*;\s*$/ &&
		    $prevline =~ /^\+\s*(?:\}(?:\s*__packed\s*)?|$Type)\s*$Ident\s*\[\s*(0|1)\s*\]\s*;\s*$/) {
			if (ERROR("FLEXIBLE_ARRAY",
				  "Use C99 flexible arrays - see https://docs.kernel.org/process/deprecated.html#zero-length-and-one-element-arrays\n" . $hereprev) &&
			    $1 == '0' && $fix) {
				$fixed[$fixlinenr - 1] =~ s/\[\s*0\s*\]/[]/;
			}
		}

# Complain about RCU Tasks Trace used outside of BPF (and of course, RCU).
		our $rcu_trace_funcs = qr{(?x:
			rcu_read_lock_trace |
			rcu_read_lock_trace_held |
			rcu_read_unlock_trace |
			call_rcu_tasks_trace |
			synchronize_rcu_tasks_trace |
			rcu_barrier_tasks_trace |
			rcu_request_urgent_qs_task
		)};
		our $rcu_trace_paths = qr{(?x:
			kernel/bpf/ |
			include/linux/bpf |
			net/bpf/ |
			kernel/rcu/ |
			include/linux/rcu
		)};
		if ($line =~ /\b($rcu_trace_funcs)\s*\(/) {
			if ($realfile !~ m{^$rcu_trace_paths}) {
				WARN("RCU_TASKS_TRACE",
				     "use of RCU tasks trace is incorrect outside BPF or core RCU code\n" . $herecurr);
			}
		}

			if (!$file && $extracted_string eq '"GPL v2"') {
				if (WARN("MODULE_LICENSE",
				     "Prefer \"GPL\" over \"GPL v2\" - see commit bf7fbeeae6db (\"module: Cure the MODULE_LICENSE \"GPL\" vs. \"GPL v2\" bogosity\")\n" . $herecurr) &&
				    $fix) {
					$fixed[$fixlinenr] =~ s/\bMODULE_LICENSE\s*\(\s*"GPL v2"\s*\)/MODULE_LICENSE("GPL")/;
				}
			}
}