section .data
	msg: db "Hello, Holberton", 10

section .text
	global main

	extern printf

	main:
		push msg
		call printf
		add esp, 4

		mov eax, 1
		xor ebx, ebx
		int 0x80
