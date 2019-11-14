include \masm32\include64\masm64rt.inc

.data
	cifra db ?, 0

.code
	main proc
		mov rax, -123; incarcare numar de afisat
		call PutI64 ; apel procedura
		invoke ExitProcess, 0 ; invoke ExitProcess API
		ret
	main endp

	PutI64 proc

	cmp rax,0
	jge @F
	mov byte ptr cifra, '-'
	invoke StdOut,addr cifra
	neg rax
	@@:
	call PutU64
	ret
	PutI64 endp

	PutU64 proc ; parametru: numar fara semn in EAX
	
		cmp rax,10
		jnl jump1
		cmp rax, 0
		jnge jump1
		mov dl,al
		add dl,'0'
		mov cifra,dl
		jmp @F
		jump1:
		test rax, rax ; EAX == 0 (conditia de iesire)
		jz @F
		xor rdx, rdx ; EDX = 10
		mov rcx, 10
		div rcx ; EDX:EAX / baza (EAX=cat, EDX = rest)
		push dx ; DX (rest) -> stiva
		call PutU64 ; apel recursiv
		pop dx ; DX <- stiva
		add dl, '0' ; conversie cifra din DL in caracter ASCII		
		mov cifra, dl
	@@:
		invoke StdOut, addr cifra
		ret
	PutU64 EndP
	
	end
