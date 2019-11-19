xor rsi,rsi 
	xor r8, r8
	starti:
	cmp rcx, 0
	je endi

	add rbx, byte ptr [rcx]
	mul rbx, rsi
	
	add r8, rbx
	xor rbx, rbx

	inc rsi

	endi:
	mov eax, 
	ret	
