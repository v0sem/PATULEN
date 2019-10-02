segment .data
_x	dw	5
segment .bss
__esp	resd	1
_y	resw	1
segment .text
global main
extern print_string, print_endofline, print_int, print_blank, print_boolean, scan_int, scan_boolean
main:
mov dword [__esp], esp
push dword _y
call scan_int
add esp, 4
mov eax, [_x]
mov edx, [_y]
sub eax, edx
push dword [eax]
call print_int
add esp, 4
mov dword esp, [__esp]
ret
