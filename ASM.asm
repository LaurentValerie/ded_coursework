.586
.MODEL FLAT, STDCALL
PUBLIC fun1

_DATA SEGMENT
	StrMas db 11 dup(?), 0
	dec1 dd 10
_DATA ENDS

_TEXT SEGMENT
	fun1 PROC num1:DWORD
		Lea EBX, StrMas
		mov ECX, 11
	metka1:
		mov BYTE PTR [EBX], ' '
		inc EBX
		Loop metka1
		mov EAX, num1
		push EAX
		OR EAX, EAX
		jns metka2
		neg EAX
	metka2:
		XOR EDX, EDX
		div dec1
		add DX, '0'
		dec EBX
		mov BYTE PTR [EBX], DL
		inc ECX
		OR EAX, EAX
		jnz metka2
		pop EAX
		OR EAX, EAX
		jns metka3
		dec EBX
		mov BYTE PTR [EBX], '-'
		inc ECX
	metka3:
		mov EAX, EBX
		ret
	fun1 ENDP
_TEXT ENDS
END