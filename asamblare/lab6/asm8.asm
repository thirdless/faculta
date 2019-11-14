 include \masm32\include64\masm64rt.inc

.data

sir label BYTE
cntr = 1
REPEAT 10
	BYTE cntr dup(cntr + 'A'-1)
	cntr = cntr + 1
ENDM
BYTE 0

.code	

  main proc

	invoke StdOut,addr sir
	invoke ExitProcess, 0
	ret
  main endp


end
