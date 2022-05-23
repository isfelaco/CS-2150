; linearSearch.s
;
; Purpose : This file contains the implementation of the function
;           mathlib, which has two routines to implement multiplication and exponential.
;
; Parameter 1 is an int pointing to an int array (rdi)
; Parameter 2 is an int for size of array (rsi)
; Parameter 3 is an int for the search target (rdx)
; Returns index of parameter 3

	global linearSearch
	section .text

linearSearch:
	xor rax, rax
	xor r14, r14
	xor al, al
start:
	cmp rax, rdx
	je found
	cmp rsi, r14
	je not_found
	mov al, [rdi]
	movzx rax, al
	add rdi, 4
	inc r14
	jmp start
not_found:
	mov rax, -1
	ret
found:
	dec r14
	mov rax, r14
	ret