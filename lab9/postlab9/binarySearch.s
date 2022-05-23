; Isabella Felaco, isf4rjk
; CS 2150, Post-lab 9
; 4/14/2022
; binarySearch.s

	global binarySearch

	section .text

; Parameter 1 is an int pointing to an int array (rdi)
; Parameter 2 is an int representing the beginning of the array (rsi)
; Parameter 3 is an int representing the ending of the array (rdx)
; Parameter 4 is an int for the search target (rcx)
; Return is index of rcx in array

binarySearch:
	xor rax, rax
	xor r14, r14		; store mid value
	xor ax, ax
	push rsi
	push rdx
	push rdi			; store pointer
start:
	pop rdi				; restore pointer value
	push rdi			; save again on stack

	cmp rsi, rdx		; while low <= high
	jg not_found		; jump if NOT low <= high (i.e. low > high)

	mov r14, rsi		; mid = low
	add r14, rdx		; mid = low + high
	shr r14, 1			; mid = (low + high) / 2
	shl r14, 2			; multiply by 4 because a[i] = 16 bits (size of int)

	add rdi, r14		; &a[mid] = &a + (size of elements)*mid

	mov eax, [rdi]		; move 16 bit value at arr[mid] into eax

	cmp rax, rcx
	jl mid_less			; if (arr[mid] < key)
	jg	mid_greater		; if (arr[mid] > key)

	shr r14, 2			; if (arr[mid] == key)
	mov rax, r14
	pop rdi
	pop rdx
	pop rsi
	ret

mid_less:
	shr r14, 2			; low = mid + 1
	mov rsi, r14
	inc rsi
	jmp start

mid_greater:
	shr r14, 2			; high = mid - 1
	mov rdx, r14
	dec rdx
	jmp start

not_found:
	mov rax, -1
	pop rdi
	pop rdx
	pop rsi
	ret