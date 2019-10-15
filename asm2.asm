; Autor:
; Nume program:
; Descriere:
; Data:

 include \masm32\include64\masm64rt.inc

.data
	carry dd 0
	var dd 543543

.code
  main proc
	mov eax, var
	
	jump1:
		cmp eax, 0
		je jump_end
		
		shr eax, 1
		jc jump_carry
		jmp jump1

	jump_carry:
		inc carry
		jmp jump1

	jump_end:

	invoke ExitProcess, 0
	ret
  main endp

end
