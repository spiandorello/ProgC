	.file	"main.c"
	.text
Ltext0:
	.cfi_sections	.debug_frame
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Entre com o tamanho do vetor: \0"
LC1:
	.ascii "%d\0"
LC2:
	.ascii "main: \0"
LC3:
	.ascii "Entre com o valor de v[%d]: \12\0"
	.align 4
LC4:
	.ascii "o somatorio dos elementodo do vetor eh : %d\12\0"
LC5:
	.ascii "vec[%d]: %d \12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB6:
	.file 1 "C:/Users/dudu/Desktop/Exercicio_1/main.c"
	.loc 1 8 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	.loc 1 8 0
	call	___main
	.loc 1 11 0
	movl	$LC0, (%esp)
	call	_printf
	.loc 1 12 0
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	.loc 1 14 0
	movl	20(%esp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, 24(%esp)
	.loc 1 16 0
	cmpl	$0, 24(%esp)
	jne	L2
	.loc 1 18 0
	movl	$LC2, (%esp)
	call	_perror
	.loc 1 19 0
	movl	$1, (%esp)
	call	_exit
L2:
	.loc 1 22 0
	movl	$0, 28(%esp)
	jmp	L3
L4:
	.loc 1 24 0 discriminator 3
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	.loc 1 25 0 discriminator 3
	movl	28(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	.loc 1 22 0 discriminator 3
	addl	$1, 28(%esp)
L3:
	.loc 1 22 0 is_stmt 0 discriminator 1
	movl	20(%esp), %eax
	cmpl	%eax, 28(%esp)
	jl	L4
	.loc 1 27 0 is_stmt 1
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_sumVector
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	.loc 1 29 0
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_revertVector
	.loc 1 31 0
	movl	$0, 28(%esp)
	jmp	L5
L6:
	.loc 1 33 0 discriminator 3
	movl	28(%esp), %eax
	leal	0(,%eax,4), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	.loc 1 31 0 discriminator 3
	addl	$1, 28(%esp)
L5:
	.loc 1 31 0 is_stmt 0 discriminator 1
	movl	20(%esp), %eax
	cmpl	%eax, 28(%esp)
	jl	L6
	.loc 1 35 0 is_stmt 1
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	.loc 1 36 0
	movl	$0, %eax
	.loc 1 37 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE6:
	.globl	_sumVector
	.def	_sumVector;	.scl	2;	.type	32;	.endef
_sumVector:
LFB7:
	.loc 1 41 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	.loc 1 42 0
	movl	$0, -8(%ebp)
	.loc 1 43 0
	movl	$0, -4(%ebp)
	jmp	L9
L10:
	.loc 1 44 0 discriminator 3
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	addl	%eax, -8(%ebp)
	.loc 1 43 0 discriminator 3
	addl	$1, -4(%ebp)
L9:
	.loc 1 43 0 is_stmt 0 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L10
	.loc 1 45 0 is_stmt 1
	movl	-8(%ebp), %eax
	.loc 1 46 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7:
	.globl	_revertVector
	.def	_revertVector;	.scl	2;	.type	32;	.endef
_revertVector:
LFB8:
	.loc 1 51 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	.loc 1 54 0
	movl	$0, -4(%ebp)
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -8(%ebp)
	jmp	L13
L14:
	.loc 1 56 0 discriminator 3
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	.loc 1 57 0 discriminator 3
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	.loc 1 58 0 discriminator 3
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 54 0 discriminator 3
	addl	$1, -4(%ebp)
	subl	$1, -8(%ebp)
L13:
	.loc 1 54 0 is_stmt 0 discriminator 1
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jl	L14
	.loc 1 60 0 is_stmt 1
	movl	8(%ebp), %eax
	.loc 1 61 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8:
Letext0:
	.file 2 "C:/Program Files (x86)/CodeBlocks/MinGW/include/stdio.h"
	.section	.debug_info,"dr"
Ldebug_info0:
	.long	0x288
	.word	0x4
	.secrel32	Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.ascii "GNU C11 5.1.0 -mtune=generic -march=pentiumpro -g\0"
	.byte	0xc
	.ascii "C:\\Users\\dudu\\Desktop\\Exercicio_1\\main.c\0"
	.long	Ltext0
	.long	Letext0-Ltext0
	.secrel32	Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x3
	.ascii "_iobuf\0"
	.byte	0x20
	.byte	0x2
	.byte	0x81
	.long	0x129
	.uleb128 0x4
	.ascii "_ptr\0"
	.byte	0x2
	.byte	0x83
	.long	0x129
	.byte	0
	.uleb128 0x4
	.ascii "_cnt\0"
	.byte	0x2
	.byte	0x84
	.long	0x12f
	.byte	0x4
	.uleb128 0x4
	.ascii "_base\0"
	.byte	0x2
	.byte	0x85
	.long	0x129
	.byte	0x8
	.uleb128 0x4
	.ascii "_flag\0"
	.byte	0x2
	.byte	0x86
	.long	0x12f
	.byte	0xc
	.uleb128 0x4
	.ascii "_file\0"
	.byte	0x2
	.byte	0x87
	.long	0x12f
	.byte	0x10
	.uleb128 0x4
	.ascii "_charbuf\0"
	.byte	0x2
	.byte	0x88
	.long	0x12f
	.byte	0x14
	.uleb128 0x4
	.ascii "_bufsiz\0"
	.byte	0x2
	.byte	0x89
	.long	0x12f
	.byte	0x18
	.uleb128 0x4
	.ascii "_tmpfname\0"
	.byte	0x2
	.byte	0x8a
	.long	0x129
	.byte	0x1c
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.long	0x9a
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x6
	.ascii "FILE\0"
	.byte	0x2
	.byte	0x8b
	.long	0xa2
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.ascii "short int\0"
	.uleb128 0x7
	.ascii "main\0"
	.byte	0x1
	.byte	0x7
	.long	0x12f
	.long	LFB6
	.long	LFE6-LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x1b3
	.uleb128 0x8
	.ascii "vet\0"
	.byte	0x1
	.byte	0x9
	.long	0x1b3
	.uleb128 0x2
	.byte	0x74
	.sleb128 24
	.uleb128 0x8
	.ascii "tamanho\0"
	.byte	0x1
	.byte	0x9
	.long	0x12f
	.uleb128 0x2
	.byte	0x74
	.sleb128 20
	.uleb128 0x8
	.ascii "i\0"
	.byte	0x1
	.byte	0x9
	.long	0x12f
	.uleb128 0x2
	.byte	0x74
	.sleb128 28
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.long	0x12f
	.uleb128 0x9
	.ascii "sumVector\0"
	.byte	0x1
	.byte	0x28
	.long	0x12f
	.long	LFB7
	.long	LFE7-LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x20e
	.uleb128 0xa
	.ascii "vec\0"
	.byte	0x1
	.byte	0x28
	.long	0x1b3
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xa
	.ascii "n\0"
	.byte	0x1
	.byte	0x28
	.long	0x12f
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x8
	.ascii "i\0"
	.byte	0x1
	.byte	0x2a
	.long	0x12f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x8
	.ascii "soma\0"
	.byte	0x1
	.byte	0x2a
	.long	0x12f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.byte	0
	.uleb128 0x9
	.ascii "revertVector\0"
	.byte	0x1
	.byte	0x32
	.long	0x272
	.long	LFB8
	.long	LFE8-LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x272
	.uleb128 0xa
	.ascii "vec\0"
	.byte	0x1
	.byte	0x32
	.long	0x1b3
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xa
	.ascii "n\0"
	.byte	0x1
	.byte	0x32
	.long	0x12f
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x8
	.ascii "i\0"
	.byte	0x1
	.byte	0x34
	.long	0x12f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x8
	.ascii "j\0"
	.byte	0x1
	.byte	0x34
	.long	0x12f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x8
	.ascii "temp\0"
	.byte	0x1
	.byte	0x34
	.long	0x12f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0xb
	.byte	0x4
	.uleb128 0xc
	.long	0x136
	.long	0x27f
	.uleb128 0xd
	.byte	0
	.uleb128 0xe
	.ascii "_iob\0"
	.byte	0x2
	.byte	0x9a
	.long	0x274
	.byte	0
	.section	.debug_abbrev,"dr"
Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x1c
	.word	0x2
	.secrel32	Ldebug_info0
	.byte	0x4
	.byte	0
	.word	0
	.word	0
	.long	Ltext0
	.long	Letext0-Ltext0
	.long	0
	.long	0
	.section	.debug_line,"dr"
Ldebug_line0:
	.section	.debug_str,"dr"
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_perror;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
