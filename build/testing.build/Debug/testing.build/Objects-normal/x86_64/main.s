	.section __DWARF,__debug_frame,regular,debug
Lsection__debug_frame:
	.section __DWARF,__debug_info,regular,debug
Lsection__debug_info:
	.section __DWARF,__debug_abbrev,regular,debug
Lsection__debug_abbrev:
	.section __DWARF,__debug_aranges,regular,debug
Lsection__debug_aranges:
	.section __DWARF,__debug_macinfo,regular,debug
Lsection__debug_macinfo:
	.section __DWARF,__debug_line,regular,debug
Lsection__debug_line:
	.section __DWARF,__debug_loc,regular,debug
Lsection__debug_loc:
	.section __DWARF,__debug_pubnames,regular,debug
Lsection__debug_pubnames:
	.section __DWARF,__debug_pubtypes,regular,debug
Lsection__debug_pubtypes:
	.section __DWARF,__debug_inlined,regular,debug
Lsection__debug_inlined:
	.section __DWARF,__debug_str,regular,debug
Lsection__debug_str:
	.section __DWARF,__debug_ranges,regular,debug
Lsection__debug_ranges:
	.section __DWARF,__debug_abbrev,regular,debug
Ldebug_abbrev0:
	.section __DWARF,__debug_info,regular,debug
Ldebug_info0:
	.section __DWARF,__debug_line,regular,debug
Ldebug_line0:
	.text
Ltext0:
	.cstring
LC0:
	.ascii "Hello, World!\0"
LC1:
	.ascii "your mom\0"
	.text
.globl _main
_main:
LFB3:
	.file 1 "/Users/moneydesktop/Development/testing/main.c"
	.loc 1 3 0
	nop
	nop
	nop
	nop
	nop
	nop
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	subq	$32, %rsp
LCFI2:
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 5 0
	leaq	LC0(%rip), %rdi
	call	_puts
LBB2:
	.loc 1 6 0
	movl	$0, -4(%rbp)
	jmp	L2
L3:
	.loc 1 7 0
	leaq	LC1(%rip), %rdi
	movl	$0, %eax
	call	_printf
	.loc 1 6 0
	incl	-4(%rbp)
L2:
	cmpl	$9, -4(%rbp)
	jle	L3
LBE2:
	.loc 1 9 0
	movl	$0, %eax
	.loc 1 10 0
	leave
	ret
LFE3:
	.section __DWARF,__debug_frame,regular,debug
Lframe0:
	.set L$set$0,LECIE0-LSCIE0
	.long L$set$0
LSCIE0:
	.long	0xffffffff
	.byte	0x1
	.ascii "\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE0:
LSFDE0:
	.set L$set$1,LEFDE0-LASFDE0
	.long L$set$1
LASFDE0:
	.set L$set$2,Lframe0-Lsection__debug_frame
	.long L$set$2
	.quad	LFB3
	.set L$set$3,LFE3-LFB3
	.quad L$set$3
	.byte	0x4
	.set L$set$4,LCFI0-LFB3
	.long L$set$4
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$5,LCFI1-LCFI0
	.long L$set$5
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE0:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$6,LECIE1-LSCIE1
	.long L$set$6
LSCIE1:
	.long	0x0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
.globl _main.eh
_main.eh:
LSFDE1:
	.set L$set$7,LEFDE1-LASFDE1
	.long L$set$7
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB3-.
	.set L$set$8,LFE3-LFB3
	.quad L$set$8
	.byte	0x0
	.byte	0x4
	.set L$set$9,LCFI0-LFB3
	.long L$set$9
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$10,LCFI1-LCFI0
	.long L$set$10
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE1:
	.text
Letext0:
	.section __DWARF,__debug_loc,regular,debug
Ldebug_loc0:
LLST0:
	.set L$set$11,LFB3-Ltext0
	.quad L$set$11
	.set L$set$12,LCFI0-Ltext0
	.quad L$set$12
	.word	0x2
	.byte	0x77
	.byte	0x8
	.set L$set$13,LCFI0-Ltext0
	.quad L$set$13
	.set L$set$14,LCFI1-Ltext0
	.quad L$set$14
	.word	0x2
	.byte	0x77
	.byte	0x10
	.set L$set$15,LCFI1-Ltext0
	.quad L$set$15
	.set L$set$16,LFE3-Ltext0
	.quad L$set$16
	.word	0x2
	.byte	0x76
	.byte	0x10
	.quad	0x0
	.quad	0x0
	.section __DWARF,__debug_info,regular,debug
	.long	0x1c9
	.word	0x2
	.set L$set$17,Ldebug_abbrev0-Lsection__debug_abbrev
	.long L$set$17
	.byte	0x8
	.byte	0x1
	.ascii "GNU C 4.2.1 (Apple Inc. build 5664)\0"
	.byte	0x1
	.ascii "/Users/moneydesktop/Development/testing/main.c\0"
	.quad	Ltext0
	.quad	Letext0
	.set L$set$18,Ldebug_line0-Lsection__debug_line
	.long L$set$18
	.byte	0x2
	.byte	0x1
	.byte	0x6
	.ascii "signed char\0"
	.byte	0x2
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.byte	0x2
	.byte	0x2
	.byte	0x5
	.ascii "short int\0"
	.byte	0x2
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.byte	0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.byte	0x2
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.byte	0x2
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.byte	0x2
	.byte	0x8
	.byte	0x7
	.ascii "long long unsigned int\0"
	.byte	0x2
	.byte	0x8
	.byte	0x5
	.ascii "long int\0"
	.byte	0x3
	.byte	0x8
	.byte	0x7
	.byte	0x2
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.byte	0x2
	.byte	0x8
	.byte	0x7
	.ascii "long unsigned int\0"
	.byte	0x4
	.byte	0x8
	.long	0x12b
	.byte	0x5
	.long	0x108
	.byte	0x6
	.byte	0x1
	.set L$set$19,LASF0-Lsection__debug_str
	.long L$set$19
	.byte	0x1
	.byte	0x3
	.byte	0x1
	.long	0xb7
	.quad	LFB3
	.quad	LFE3
	.set L$set$20,LLST0-Lsection__debug_loc
	.long L$set$20
	.long	0x192
	.byte	0x7
	.ascii "argc\0"
	.byte	0x1
	.byte	0x3
	.long	0xb7
	.byte	0x2
	.byte	0x91
	.byte	0x5c
	.byte	0x7
	.ascii "argv\0"
	.byte	0x1
	.byte	0x3
	.long	0x192
	.byte	0x2
	.byte	0x91
	.byte	0x50
	.byte	0x8
	.quad	LBB2
	.quad	LBE2
	.byte	0x9
	.ascii "i\0"
	.byte	0x1
	.byte	0x6
	.long	0xb7
	.byte	0x2
	.byte	0x91
	.byte	0x6c
	.byte	0x0
	.byte	0x0
	.byte	0x4
	.byte	0x8
	.long	0x125
	.byte	0xa
	.long	0xb7
	.long	0x1a3
	.byte	0xb
	.byte	0x0
	.byte	0xc
	.ascii "__CFConstantStringClassReference\0"
	.long	0x198
	.byte	0x1
	.byte	0x1
	.byte	0x1
	.byte	0x0
	.section __DWARF,__debug_abbrev,regular,debug
	.byte	0x1
	.byte	0x11
	.byte	0x1
	.byte	0x25
	.byte	0x8
	.byte	0x13
	.byte	0xb
	.byte	0x3
	.byte	0x8
	.byte	0x11
	.byte	0x1
	.byte	0x12
	.byte	0x1
	.byte	0x10
	.byte	0x6
	.byte	0x0
	.byte	0x0
	.byte	0x2
	.byte	0x24
	.byte	0x0
	.byte	0xb
	.byte	0xb
	.byte	0x3e
	.byte	0xb
	.byte	0x3
	.byte	0x8
	.byte	0x0
	.byte	0x0
	.byte	0x3
	.byte	0x24
	.byte	0x0
	.byte	0xb
	.byte	0xb
	.byte	0x3e
	.byte	0xb
	.byte	0x0
	.byte	0x0
	.byte	0x4
	.byte	0xf
	.byte	0x0
	.byte	0xb
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x0
	.byte	0x0
	.byte	0x5
	.byte	0x26
	.byte	0x0
	.byte	0x49
	.byte	0x13
	.byte	0x0
	.byte	0x0
	.byte	0x6
	.byte	0x2e
	.byte	0x1
	.byte	0x3f
	.byte	0xc
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x27
	.byte	0xc
	.byte	0x49
	.byte	0x13
	.byte	0x11
	.byte	0x1
	.byte	0x12
	.byte	0x1
	.byte	0x40
	.byte	0x6
	.byte	0x1
	.byte	0x13
	.byte	0x0
	.byte	0x0
	.byte	0x7
	.byte	0x5
	.byte	0x0
	.byte	0x3
	.byte	0x8
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x2
	.byte	0xa
	.byte	0x0
	.byte	0x0
	.byte	0x8
	.byte	0xb
	.byte	0x1
	.byte	0x11
	.byte	0x1
	.byte	0x12
	.byte	0x1
	.byte	0x0
	.byte	0x0
	.byte	0x9
	.byte	0x34
	.byte	0x0
	.byte	0x3
	.byte	0x8
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x2
	.byte	0xa
	.byte	0x0
	.byte	0x0
	.byte	0xa
	.byte	0x1
	.byte	0x1
	.byte	0x49
	.byte	0x13
	.byte	0x1
	.byte	0x13
	.byte	0x0
	.byte	0x0
	.byte	0xb
	.byte	0x21
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.byte	0xc
	.byte	0x34
	.byte	0x0
	.byte	0x3
	.byte	0x8
	.byte	0x49
	.byte	0x13
	.byte	0x3f
	.byte	0xc
	.byte	0x34
	.byte	0xc
	.byte	0x3c
	.byte	0xc
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section __DWARF,__debug_pubnames,regular,debug
	.long	0x17
	.word	0x2
	.set L$set$21,Ldebug_info0-Lsection__debug_info
	.long L$set$21
	.long	0x1cd
	.long	0x130
	.ascii "main\0"
	.long	0x0
	.section __DWARF,__debug_pubtypes,regular,debug
	.long	0xe
	.word	0x2
	.set L$set$22,Ldebug_info0-Lsection__debug_info
	.long L$set$22
	.long	0x1cd
	.long	0x0
	.section __DWARF,__debug_aranges,regular,debug
	.long	0x2c
	.word	0x2
	.set L$set$23,Ldebug_info0-Lsection__debug_info
	.long L$set$23
	.byte	0x8
	.byte	0x0
	.word	0x0
	.word	0x0
	.quad	Ltext0
	.set L$set$24,Letext0-Ltext0
	.quad L$set$24
	.quad	0x0
	.quad	0x0
	.section __DWARF,__debug_str,regular,debug
LASF0:
	.ascii "main\0"
	.subsections_via_symbols
