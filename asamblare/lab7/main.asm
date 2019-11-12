; Autor:
; Nume program:
; Descriere:
; Data:

.data
	numar dd 0

.code
 AsmFunction proc

	push rbp ; salvare EBP
	mov rbp, rsp ; stack frame
	mov qword ptr [rbp+16], rcx ; Arg 1
	mov qword ptr [rbp+24], rdx ; Arg 2
	
	func:



	inc numar
	cmp rdx, numar
	je endi
	jmp func

	endi:

	mov eax, [rcx]


	mov rsp, rbp ; eliberare stiva
	pop rbp ; refacere EBP
	ret
 AsmFunction endp
end
