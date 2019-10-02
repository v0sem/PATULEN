segment .data
_msg	db	'Hello world!!', 0
segment .bss
__esp	resd	1
segment .text
global main
extern print_string, print_endofline, print_int, print_blank, print_boolean, scan_int, scan_boolean
main:
mov dword [__esp], esp
push dword _msg
call print_string
add esp, 4
mov dword esp, [__esp]
ret
