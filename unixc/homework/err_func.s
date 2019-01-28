	.file	"err_func.c"
	.text
.globl err_sys
	.type	err_sys, @function
err_sys:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$224, %rsp
	movq	%rsi, -168(%rbp)
	movq	%rdx, -160(%rbp)
	movq	%rcx, -152(%rbp)
	movq	%r8, -144(%rbp)
	movq	%r9, -136(%rbp)
	movzbl	%al, %eax
	leaq	0(,%rax,4), %rdx
	movl	$.L2, %eax
	subq	%rdx, %rax
	leaq	-1(%rbp), %rdx
	jmp	*%rax
	movaps	%xmm7, -15(%rdx)
	movaps	%xmm6, -31(%rdx)
	movaps	%xmm5, -47(%rdx)
	movaps	%xmm4, -63(%rdx)
	movaps	%xmm3, -79(%rdx)
	movaps	%xmm2, -95(%rdx)
	movaps	%xmm1, -111(%rdx)
	movaps	%xmm0, -127(%rdx)
.L2:
	movq	%rdi, -216(%rbp)
	leaq	-208(%rbp), %rax
	movl	$8, (%rax)
	leaq	-208(%rbp), %rax
	movl	$48, 4(%rax)
	leaq	-208(%rbp), %rax
	leaq	16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	leaq	-208(%rbp), %rax
	leaq	-176(%rbp), %rdx
	movq	%rdx, 16(%rax)
	call	__errno_location
	movl	(%rax), %eax
	leaq	-208(%rbp), %rcx
	movq	-216(%rbp), %rdx
	movl	%eax, %esi
	movl	$1, %edi
	call	err_doit
	movl	$1, %edi
	call	exit
	.cfi_endproc
.LFE0:
	.size	err_sys, .-err_sys
	.section	.rodata
.LC0:
	.string	":%s"
.LC1:
	.string	"\n"
	.text
	.type	err_doit, @function
err_doit:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$4136, %rsp
	movl	%edi, -4132(%rbp)
	movl	%esi, -4136(%rbp)
	movq	%rdx, -4144(%rbp)
	movq	%rcx, -4152(%rbp)
	movq	-4152(%rbp), %rcx
	movq	-4144(%rbp), %rdx
	leaq	-4128(%rbp), %rax
	movl	$4095, %esi
	movq	%rax, %rdi
	.cfi_offset 3, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	call	vsnprintf
	cmpl	$0, -4132(%rbp)
	je	.L5
	movl	-4136(%rbp), %eax
	movl	%eax, %edi
	call	strerror
	movq	%rax, %r12
	movl	$.LC0, %ebx
	leaq	-4128(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movl	$4095, %edx
	movq	%rdx, %r13
	subq	%rax, %r13
	leaq	-4128(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, %rdx
	leaq	-4128(%rbp), %rax
	addq	%rdx, %rax
	movq	%r12, %rcx
	movq	%rbx, %rdx
	movq	%r13, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
.L5:
	movl	$.LC1, %edx
	leaq	-4128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	movq	stderr(%rip), %rax
	movq	%rax, %rdx
	leaq	-4128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	movl	$0, %edi
	call	fflush
	addq	$4136, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	err_doit, .-err_doit
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-18)"
	.section	.note.GNU-stack,"",@progbits
