	.file	"main.c"
	.text
Ltext0:
	.cfi_sections	.debug_frame
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "r\0"
LC1:
	.ascii "arquivo_entrada.mif\0"
LC2:
	.ascii "Error ao abrir arquivo\0"
LC3:
	.ascii "%d      :       %x;\12\0"
LC4:
	.ascii "Armazenado:  [%d]  :    %x \12\0"
LC5:
	.ascii "wb\0"
LC6:
	.ascii "saida.bin\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB6:
	.file 1 "C:/Users/dudu/Documents/Engenharia/SEMESTRE 5/Programa\347\343o 2/AULA 3 - E-S DADOS/EXERCICIO_E_S_DADOS/main.c"
	.loc 1 18 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$1120, %esp
	.loc 1 18 0
	call	___main
	.loc 1 20 0
	movl	$0, 1112(%esp)
	.loc 1 21 0
	movl	$0, 1108(%esp)
	.loc 1 24 0
	movl	$0, 1048(%esp)
	.loc 1 25 0
	movl	$0, 1044(%esp)
	.loc 1 26 0
	movl	$0, 1116(%esp)
	.loc 1 27 0
	movl	$0, 1104(%esp)
	.loc 1 32 0
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_fopen
	movl	%eax, 1112(%esp)
	.loc 1 34 0
	cmpl	$0, 1112(%esp)
	jne	L3
	.loc 1 36 0
	movl	$LC2, (%esp)
	call	_perror
	.loc 1 37 0
	movl	$1, (%esp)
	call	_exit
L5:
	.loc 1 44 0
	movl	1112(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$50, 4(%esp)
	leal	1054(%esp), %eax
	movl	%eax, (%esp)
	call	_fgets
	.loc 1 48 0
	leal	1044(%esp), %eax
	movl	%eax, 12(%esp)
	leal	1048(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC3, 4(%esp)
	leal	1054(%esp), %eax
	movl	%eax, (%esp)
	call	_sscanf
	movl	%eax, 1104(%esp)
	.loc 1 55 0
	cmpl	$2, 1104(%esp)
	jne	L4
	.loc 1 55 0 is_stmt 0 discriminator 1
	movl	1048(%esp), %eax
	cmpl	$255, %eax
	jg	L4
	.loc 1 57 0 is_stmt 1
	movl	1048(%esp), %eax
	movl	1044(%esp), %edx
	movl	%edx, 20(%esp,%eax,4)
	.loc 1 60 0
	movl	1044(%esp), %edx
	movl	1048(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
L4:
	.loc 1 63 0
	addl	$1, 1116(%esp)
L3:
	.loc 1 41 0
	movl	1112(%esp), %eax
	movl	12(%eax), %eax
	andl	$16, %eax
	.loc 1 41 0
	testl	%eax, %eax
	je	L5
	.loc 1 66 0
	movl	1112(%esp), %eax
	movl	%eax, (%esp)
	call	_fclose
	.loc 1 68 0
	movl	$LC5, 4(%esp)
	movl	$LC6, (%esp)
	call	_fopen
	movl	%eax, 1108(%esp)
	.loc 1 75 0
	movl	1108(%esp), %eax
	movl	%eax, 12(%esp)
	movl	$256, 8(%esp)
	movl	$4, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	.loc 1 77 0
	movl	1108(%esp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	.loc 1 79 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE6:
Letext0:
	.file 2 "C:/Program Files (x86)/CodeBlocks/MinGW/include/stdio.h"
	.file 3 "C:/Program Files (x86)/CodeBlocks/MinGW/include/stdint.h"
	.section	.debug_info,"dr"
Ldebug_info0:
	.long	0x2e0
	.word	0x4
	.secrel32	Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.ascii "GNU C11 5.1.0 -mtune=generic -march=pentiumpro -g\0"
	.byte	0xc
	.ascii "C:\\Users\\dudu\\Documents\\Engenharia\\SEMESTRE 5\\Programa\347\343o 2\\AULA 3 - E-S DADOS\\EXERCICIO_E_S_DADOS\\main.c\0"
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
	.long	0x16a
	.uleb128 0x4
	.ascii "_ptr\0"
	.byte	0x2
	.byte	0x83
	.long	0x16a
	.byte	0
	.uleb128 0x4
	.ascii "_cnt\0"
	.byte	0x2
	.byte	0x84
	.long	0x170
	.byte	0x4
	.uleb128 0x4
	.ascii "_base\0"
	.byte	0x2
	.byte	0x85
	.long	0x16a
	.byte	0x8
	.uleb128 0x4
	.ascii "_flag\0"
	.byte	0x2
	.byte	0x86
	.long	0x170
	.byte	0xc
	.uleb128 0x4
	.ascii "_file\0"
	.byte	0x2
	.byte	0x87
	.long	0x170
	.byte	0x10
	.uleb128 0x4
	.ascii "_charbuf\0"
	.byte	0x2
	.byte	0x88
	.long	0x170
	.byte	0x14
	.uleb128 0x4
	.ascii "_bufsiz\0"
	.byte	0x2
	.byte	0x89
	.long	0x170
	.byte	0x18
	.uleb128 0x4
	.ascii "_tmpfname\0"
	.byte	0x2
	.byte	0x8a
	.long	0x16a
	.byte	0x1c
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.long	0xdb
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x6
	.ascii "FILE\0"
	.byte	0x2
	.byte	0x8b
	.long	0xe3
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
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.ascii "signed char\0"
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.uleb128 0x6
	.ascii "uint32_t\0"
	.byte	0x3
	.byte	0x20
	.long	0xb5
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.ascii "long long unsigned int\0"
	.uleb128 0x7
	.ascii "main\0"
	.byte	0x1
	.byte	0x11
	.long	0x170
	.long	LFB6
	.long	LFE6-LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x29a
	.uleb128 0x8
	.ascii "fp\0"
	.byte	0x1
	.byte	0x14
	.long	0x29a
	.uleb128 0x3
	.byte	0x74
	.sleb128 1112
	.uleb128 0x8
	.ascii "fp_saida\0"
	.byte	0x1
	.byte	0x15
	.long	0x29a
	.uleb128 0x3
	.byte	0x74
	.sleb128 1108
	.uleb128 0x8
	.ascii "buffer\0"
	.byte	0x1
	.byte	0x16
	.long	0x2a0
	.uleb128 0x3
	.byte	0x74
	.sleb128 1054
	.uleb128 0x8
	.ascii "endereco\0"
	.byte	0x1
	.byte	0x18
	.long	0x170
	.uleb128 0x3
	.byte	0x74
	.sleb128 1048
	.uleb128 0x8
	.ascii "dado\0"
	.byte	0x1
	.byte	0x19
	.long	0x170
	.uleb128 0x3
	.byte	0x74
	.sleb128 1044
	.uleb128 0x8
	.ascii "linha\0"
	.byte	0x1
	.byte	0x1a
	.long	0x170
	.uleb128 0x3
	.byte	0x74
	.sleb128 1116
	.uleb128 0x8
	.ascii "ret\0"
	.byte	0x1
	.byte	0x1b
	.long	0x170
	.uleb128 0x3
	.byte	0x74
	.sleb128 1104
	.uleb128 0x8
	.ascii "dados\0"
	.byte	0x1
	.byte	0x1c
	.long	0x2bc
	.uleb128 0x2
	.byte	0x74
	.sleb128 20
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.long	0x177
	.uleb128 0x9
	.long	0xdb
	.long	0x2b0
	.uleb128 0xa
	.long	0x2b0
	.byte	0x31
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "sizetype\0"
	.uleb128 0x9
	.long	0x1cd
	.long	0x2cc
	.uleb128 0xa
	.long	0x2b0
	.byte	0xff
	.byte	0
	.uleb128 0x9
	.long	0x177
	.long	0x2d7
	.uleb128 0xb
	.byte	0
	.uleb128 0xc
	.ascii "_iob\0"
	.byte	0x2
	.byte	0x9a
	.long	0x2cc
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
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xc
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
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_perror;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_fgets;	.scl	2;	.type	32;	.endef
	.def	_sscanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
