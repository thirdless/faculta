; Autor:
; Nume program:
; Descriere:
; Data:

 include \masm32\include64\masm64rt.inc


.data
  numar dq 0
  sir db "123456",0
.code
AtoU proc

	lea rbx, sir
	xor rax, rax
	;movzx rax, byte ptr [rbx]
	;sub rax, '0'
	mov rcx, 10
repi:
	mul rcx
	
	movzx r8, byte ptr [rbx]
	sub r8,'0'
	add rax,r8
	inc rbx
	cmp byte ptr[rbx],0
	jne repi
	

	ret
AtoU endp

  main proc
  xor rax,rax
  xor rdx,rdx
	call AtoU
	conout rax
	invoke ExitProcess, 0
  main endp
end
