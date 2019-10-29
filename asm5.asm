include \masm32\include64\masm64rt.inc

.data
	cifra db ?, 0
	amaifostodataacolo db 0
.code
	main proc
		mov eax, 0; incarcare numar de afisat
		call PutU32 ; apel procedura
		invoke ExitProcess, 0 ; invoke ExitProcess API
		ret
	main endp

	PutU32 proc ; parametru: numar fara semn in EAX
	
		cmp eax,10
		jnl jump1
		mov dl,al
		add dl,'0'
		mov cifra,dl
		jmp @F
		jump1:
		test eax, eax ; EAX == 0 (conditia de iesire)
		jz @F
		xor edx, edx ; EDX = 10
		mov ecx, 10
		div ecx ; EDX:EAX / baza (EAX=cat, EDX = rest)
		push dx ; DX (rest) -> stiva
		call PutU32 ; apel recursiv
		pop dx ; DX <- stiva
		add dl, '0' ; conversie cifra din DL in caracter ASCII
		mov cifra, dl
	@@:
		invoke StdOut, addr cifra
		ret
	PutU32 EndP
	
	end
