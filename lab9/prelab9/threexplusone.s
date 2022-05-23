; Isabella Felaco, isf4rjk
; CS 2150, Pre-lab 9
; 4/11/2022
; threexplusone.s

; optimizations:
; moved around code so that there were less jumps (ex: moving the cmp-je done to the first lines, only jumping once to an even subroutine, rather than having both odd and even subroutines)
; instead of using idiv to determine whether x was even/odd, I used the test command to look at the least significant bit of x
; instead of using imul/inc to calculate 3x+1, I used lea

	global threexplusone

	section .text

; Parameter 1 is the integer (rdi)
; Return is number of iterations

threexplusone:
	cmp rdi, 1			; if rdi == 1, we jump to end and return
	je done
	mov rax, rdi
	test al, 1			; look at least significant bit of x
	jz even				; if x is even, jump
	lea rdi, [3*rdi+1]	; if x is odd, x = 3x + 1
	jmp recurse
even: 
	shr rdi, 1			; x / 2
	mov rax, rdi
recurse:
	inc r14				; number of steps += 1
	call threexplusone
done:
	mov rax, r14		; move the number of steps to the return value
	ret