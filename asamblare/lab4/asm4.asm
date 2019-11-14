include \masm32\include64\masm64rt.inc
.data
string db "Sir de caractere!", 0
num dd 0
.code
 main proc

 xor ecx, ecx
 not ecx
 xor al, al
 lea rdi, string

 repne scasb
 lea ecx, [ecx + 2]
 not ecx

invoke ExitProcess, 0 ; invoke ExitProcess API
ret
 main endp
end
