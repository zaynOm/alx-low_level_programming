section .data
	msg: db "Hello, Holberton", 10

section .text
	global _start

	extern printf
	
	_start:
		push msg
		call printf
		add esp, 4

		mov eax, 1
		xor ebx, ebx
		int 0x80
	
