	.file	"complex.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"\nInside Constructor.\n"
	.section	.text._ZN7ComplexC2Edd,"axG",@progbits,_ZN7ComplexC5Edd,comdat
	.align 2
	.weak	_ZN7ComplexC2Edd
	.type	_ZN7ComplexC2Edd, @function
_ZN7ComplexC2Edd:
.LFB2324:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movq	-8(%rbp), %rax
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movq	-8(%rbp), %rax
	movsd	-24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2324:
	.size	_ZN7ComplexC2Edd, .-_ZN7ComplexC2Edd
	.weak	_ZN7ComplexC1Edd
	.set	_ZN7ComplexC1Edd,_ZN7ComplexC2Edd
	.section	.rodata
.LC1:
	.string	"\nInside C_cons\n"
	.section	.text._ZN7ComplexC2ERKS_,"axG",@progbits,_ZN7ComplexC5ERKS_,comdat
	.align 2
	.weak	_ZN7ComplexC2ERKS_
	.type	_ZN7ComplexC2ERKS_, @function
_ZN7ComplexC2ERKS_:
.LFB2327:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movsd	(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, (%rax)
	movq	-16(%rbp), %rax
	movsd	8(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2327:
	.size	_ZN7ComplexC2ERKS_, .-_ZN7ComplexC2ERKS_
	.weak	_ZN7ComplexC1ERKS_
	.set	_ZN7ComplexC1ERKS_,_ZN7ComplexC2ERKS_
	.section	.rodata
.LC2:
	.string	"\nInside Destructor.\n"
	.section	.text._ZN7ComplexD2Ev,"axG",@progbits,_ZN7ComplexD5Ev,comdat
	.align 2
	.weak	_ZN7ComplexD2Ev
	.type	_ZN7ComplexD2Ev, @function
_ZN7ComplexD2Ev:
.LFB2330:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2330
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2330:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZN7ComplexD2Ev,"aG",@progbits,_ZN7ComplexD5Ev,comdat
.LLSDA2330:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2330-.LLSDACSB2330
.LLSDACSB2330:
.LLSDACSE2330:
	.section	.text._ZN7ComplexD2Ev,"axG",@progbits,_ZN7ComplexD5Ev,comdat
	.size	_ZN7ComplexD2Ev, .-_ZN7ComplexD2Ev
	.weak	_ZN7ComplexD1Ev
	.set	_ZN7ComplexD1Ev,_ZN7ComplexD2Ev
	.section	.text._ZN7Complex10setComplexEdd,"axG",@progbits,_ZN7Complex10setComplexEdd,comdat
	.align 2
	.weak	_ZN7Complex10setComplexEdd
	.type	_ZN7Complex10setComplexEdd, @function
_ZN7Complex10setComplexEdd:
.LFB2332:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movq	-8(%rbp), %rax
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movq	-8(%rbp), %rax
	movsd	-24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2332:
	.size	_ZN7Complex10setComplexEdd, .-_ZN7Complex10setComplexEdd
	.section	.rodata
.LC3:
	.string	"\n Complex NO. : "
.LC4:
	.string	" + j"
	.section	.text._ZN7Complex5printEv,"axG",@progbits,_ZN7Complex5printEv,comdat
	.align 2
	.weak	_ZN7Complex5printEv
	.type	_ZN7Complex5printEv, @function
_ZN7Complex5printEv:
.LFB2333:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC3(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2333:
	.size	_ZN7Complex5printEv, .-_ZN7Complex5printEv
	.section	.text._ZN7Complex7modulusEv,"axG",@progbits,_ZN7Complex7modulusEv,comdat
	.align 2
	.weak	_ZN7Complex7modulusEv
	.type	_ZN7Complex7modulusEv, @function
_ZN7Complex7modulusEv:
.LFB2334:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	$2, %edi
	movq	%rax, %xmm0
	call	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	movsd	%xmm0, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movl	$2, %edi
	movq	%rax, %xmm0
	call	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	movapd	%xmm0, %xmm1
	addsd	-32(%rbp), %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	cvttsd2sil	%xmm0, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2334:
	.size	_ZN7Complex7modulusEv, .-_ZN7Complex7modulusEv
	.section	.rodata
.LC9:
	.string	"\n1-Complex b; : "
.LC12:
	.string	"\nComplex c(.,.) : "
.LC13:
	.string	"\nComplex d=c(.,.) @definn. : "
	.align 8
.LC14:
	.string	"\n2-Complex b=a (updt frm deflt): "
	.text
	.globl	main
	.type	main, @function
main:
.LFB2335:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2335
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movsd	.LC5(%rip), %xmm0
	movq	.LC6(%rip), %rdx
	leaq	-32(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
.LEHB0:
	call	_ZN7ComplexC1Edd
.LEHE0:
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Complex7modulusEv
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
.LEHB1:
	call	_ZN7Complex5printEv
	movsd	.LC7(%rip), %xmm0
	movq	.LC7(%rip), %rdx
	leaq	-32(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN7Complex10setComplexEdd
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Complex5printEv
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-48(%rbp), %rax
	pxor	%xmm1, %xmm1
	movq	.LC8(%rip), %rdx
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
.LEHE1:
	leaq	.LC9(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
.LEHB2:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Complex5printEv
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movsd	.LC10(%rip), %xmm0
	movq	.LC11(%rip), %rdx
	leaq	-64(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN7ComplexC1Edd
.LEHE2:
	leaq	.LC12(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
.LEHB3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Complex5printEv
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-64(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7ComplexC1ERKS_
.LEHE3:
	leaq	.LC13(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
.LEHB4:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Complex5printEv
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	leaq	.LC14(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Complex5printEv
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE4:
	movl	$0, %ebx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	movl	%ebx, %eax
	jmp	.L18
.L17:
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	jmp	.L11
.L16:
	movq	%rax, %rbx
.L11:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	jmp	.L12
.L15:
	movq	%rax, %rbx
.L12:
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	jmp	.L13
.L14:
	movq	%rax, %rbx
.L13:
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7ComplexD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
.L18:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2335:
	.section	.gcc_except_table,"a",@progbits
.LLSDA2335:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2335-.LLSDACSB2335
.LLSDACSB2335:
	.uleb128 .LEHB0-.LFB2335
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2335
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L14-.LFB2335
	.uleb128 0
	.uleb128 .LEHB2-.LFB2335
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L15-.LFB2335
	.uleb128 0
	.uleb128 .LEHB3-.LFB2335
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L16-.LFB2335
	.uleb128 0
	.uleb128 .LEHB4-.LFB2335
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L17-.LFB2335
	.uleb128 0
	.uleb128 .LEHB5-.LFB2335
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE2335:
	.text
	.size	main, .-main
	.section	.text._ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,"axG",@progbits,_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_,comdat
	.weak	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.type	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, @function
_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_:
.LFB2651:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movsd	%xmm0, -8(%rbp)
	movl	%edi, -12(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-12(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2651:
	.size	_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_, .-_ZSt3powIdiEN9__gnu_cxx11__promote_2IT_T0_NS0_9__promoteIS2_XsrSt12__is_integerIS2_E7__valueEE6__typeENS4_IS3_XsrS5_IS3_E7__valueEE6__typeEE6__typeES2_S3_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2990:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L23
	cmpl	$65535, -8(%rbp)
	jne	.L23
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L23:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2990:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2991:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2991:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
.LC5:
	.long	-1717986918
	.long	1075157401
	.align 8
.LC6:
	.long	858993459
	.long	1074475827
	.align 8
.LC7:
	.long	0
	.long	1075052544
	.align 8
.LC8:
	.long	0
	.long	0
	.align 8
.LC10:
	.long	0
	.long	1074921472
	.align 8
.LC11:
	.long	1717986918
	.long	1073899110
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Debian 11.2.0-13) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
