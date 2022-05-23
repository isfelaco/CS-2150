; mathlib.s
;
; Purpose : This file contains the implementation of the function
;           mathlib, which has two routines to implement multiplication and exponential.
;
; Parameter 1 (in rdi) is the first integer
; Parameter 2 (in rsi) is the second integer
; Return values are long that are the result of multiplication and exponentiation of the integers

	global product
	section .text
product:
	xor	rax, rax		; zero out the return register
	xor	r10, r10		; zero out the counter i
prod_start:	
	cmp	r10, rsi	 	; does i == n?
	je	prod_done		; if so, we are done with the loop
	add	rax, rdi 		; add rdi to rax
	inc	r10				; increment our counter i
	jmp	prod_start		; we are done with this loop iteration
prod_done:	
	ret

	global power
	section .text
power:
	cmp rsi, 0
	mov rax, 1
	jg pow_start 
	ret
pow_start:	
	dec rsi
	call power
	mov rsi, rax
	call product
	jmp pow_done
pow_done:	
	ret