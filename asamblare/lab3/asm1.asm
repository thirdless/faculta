; Autor:
; Nume program:
; Descriere:
; Data:

 include \masm32\include64\masm64rt.inc 

.data
 va dd 5
 vb dd 9
 vc dd 12
 vd dd 6
 med dd ?

.code
  main proc
	
	mov eax,va
	add eax,vb
	add eax,vc
	add eax,vd	
	shr eax, 2
	mov med, eax

	invoke ExitProcess, 0
	ret
  main endp

end
