; Autor:
; Nume program:
; Descriere:
; Data:

 include \masm32\include64\masm64rt.inc 

.data
 va dd 7
 vb dd 9
 vc dd 9
 gr dd ?

.code
  main proc
	
	mov eax,va
	cmp eax,vb
	jnge et_else
		mov gr, eax
		jmp et_end
	et_else:
		;if not great or equal
		mov ebx,vb
		mov gr, ebx
		jmp et_end
	et_end:
	mov eax, gr
	cmp eax, vc
	jnge et_else1
		jmp et_end1
	et_else1:
		mov ebx, vc
		mov gr,ebx
		jmp et_end1
	et_end1:

	invoke ExitProcess, 0
	ret
  main endp

end
