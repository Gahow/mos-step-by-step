#define STACKBASE   0x80000000
#define STACKTOP    (STACKBASE + 4 * 1024 * 1024)

.text
.global _entry

_entry:
	la	$sp, STACKTOP
	j	main
