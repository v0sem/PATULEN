segment .data
	_string_1 db	"Menú: [1] Resta. [2] Multiplicación. [3] Potencia 2 (número al cuadrado). [4] Salir.", 0
	_string_2 db	"Su opción: ", 0
	_resta	db	" - ", 0
	_multiplicar	db	" * ", 0
	_igual	db	" = ", 0

segment .bss
	__esp	resd	1
	_option	resd	1
	_operando_1	resw	1
	_operando_2 resw	1

segment .text
	global main
	extern print_string, print_endofline, print_int
	extern scan_int

main:
	mov dword [__esp] , esp

menu:
	push dword _string_1
	call print_string
	add esp, 4
	call print_endofline
	
	push dword _string_2
	call print_string
	add esp, 4

	push dword _option
	call scan_int
	add esp, 4
	push dword [_option]
	
	pop eax
	cmp eax, 1
	je resta
	cmp eax, 2
	je multiplic
	cmp eax, 3
	je pot
	cmp eax, 4
	je quit
	call menu

resta:

	mov dword [_operando_1], 10
	push dword [_operando_1]
	pop dword ebx
	push dword [_operando_1]
	call print_int
	add esp, 4

	push dword _resta
	call print_string
	add esp, 4

	mov dword [_operando_2], 12
	push dword [_operando_2]
	pop dword ecx
	push dword [_operando_2]
	call print_int
	add esp, 4

	push dword _igual
	call print_string
	add esp, 4

	sub ebx, ecx
	push dword ebx
	call print_int
	add esp, 4
	call print_endofline

	call menu

multiplic:
	mov dword [_operando_1], 10
	push dword [_operando_1]
	pop dword ebx
	push dword [_operando_1]
	call print_int
	add esp, 4

	push dword _multiplicar
	call print_string
	add esp, 4

	mov dword [_operando_2], 12
	push dword [_operando_2]
	pop dword ecx
	push dword [_operando_2]
	call print_int
	add esp, 4

	push dword _igual
	call print_string
	add esp, 4

	mov eax, ebx
	imul ecx
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	call menu

pot:
	mov dword [_operando_1], 10
	push dword [_operando_1]
	pop dword ebx
	push dword [_operando_1]
	call print_int
	add esp, 4

	push dword _multiplicar
	call print_string
	add esp, 4

	mov dword [_operando_1], 10
	push dword [_operando_1]
	call print_int
	add esp, 4

	push dword _igual
	call print_string
	add esp, 4

	mov eax, ebx
	imul ebx
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	call menu
quit:
	mov dword esp, [__esp]
	ret
