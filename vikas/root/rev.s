	.file	"rev.c"
	.text
	.section	.rodata
.LC0:
	.string	"original array: "
.LC1:
	.string	"%d\t"
.LC2:
	.string	"reversed array: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -32(%rbp)
	movl	$20, -28(%rbp)
	movl	$30, -24(%rbp)
	movl	$40, -20(%rbp)
	movl	$50, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, -40(%rbp)
	jmp	.L2
.L3:
	movl	-40(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -40(%rbp)
.L2:
	cmpl	$5, -40(%rbp)
	jle	.L3
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$5, -36(%rbp)
	jmp	.L4
.L5:
	movl	-36(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	subl	$1, -36(%rbp)
.L4:
	cmpl	$0, -36(%rbp)
	jg	.L5
	movl	$10, %edi
	call	putchar@PLT
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
