segment .data
    _label_menu db "Menu: [1] Option 1. [2] Option 2. [3] Quit.", 0
    _label_choice db "Your choice? ", 0
    _process1 db "Process option 1 ... ", 0
    _process2 db "Process option 2 ...", 0

segment .bss
	__esp    resd 1
	_option  resd 1

segment .text
	global main
	extern print_string, print_endofline, scan_int
    
main:
	mov dword [__esp], esp
      	   
menu:
    ;Mostrar menú
	push dword _label_menu 
	call print_string
	add esp, 4	
	call print_endofline

    ;Elegir opción
    push dword _label_choice 
	call print_string
	add esp, 4	
	push dword _option
    call scan_int
	add esp, 4
	push dword [_option]
	
    ;Ejecutar opción de menú
	pop eax
	cmp eax, 1
	je option1
	cmp eax, 2
	je option2
	cmp eax, 3
	je quit
	call menu
	
option1:
    push dword _process1
	call print_string
	add esp, 4	
	call print_endofline
    call menu	
	
option2:
    push dword _process2
	call print_string
	add esp, 4	
	call print_endofline
    call menu		
	
quit: 
	mov dword esp, [__esp]
	ret