	.file	"circularlistmain.c"
	.text
	.section	.rodata
.LC0:
	.string	"the sum of all is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -32(%rbp)
	leaq	-32(%rbp), %rax
	movl	$18, %esi
	movq	%rax, %rdi
	call	addnode@PLT
	leaq	-32(%rbp), %rax
	movl	$27, %esi
	movq	%rax, %rdi
	call	addnode@PLT
	leaq	-32(%rbp), %rax
	movl	$35, %esi
	movq	%rax, %rdi
	call	addnode@PLT
	leaq	-32(%rbp), %rax
	movl	$56, %esi
	movq	%rax, %rdi
	call	addnode@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	sumvalues@PLT
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L2
.L4:
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-32(%rbp), %rax
	cmpq	%rax, -24(%rbp)
	je	.L6
.L2:
	cmpq	$0, -24(%rbp)
	jne	.L4
	jmp	.L3
.L6:
	nop
.L3:
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
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
