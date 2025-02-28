#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE * f;

	if(argc != 4){
		printf("Required format: %s, op1, op2", argv[0]);
		return -1;
	}

	f = fopen(argv[1], "w");
	if(!f)
		return -1;

	fprintf(f ,"segment .data\n");
	fprintf(f ,"\t_string_1 db\t\"Menú: [1] Resta. [2] Multiplicación. [3] Potencia 2 (número al cuadrado). [4] Salir.\", 0\n");
	fprintf(f ,"\t_string_2 db\t\"Su opción: \", 0\n");
	fprintf(f ,"\t_resta\tdb\t\" - \", 0\n");
	fprintf(f ,"\t_multiplicar\tdb\t\" * \", 0\n");
	fprintf(f ,"\t_igual\tdb\t\" = \", 0\n");
	fprintf(f ,"\n");
	fprintf(f ,"segment .bss\n");
	fprintf(f ,"\t__esp\tresd\t1\n");
	fprintf(f ,"\t_option\tresd\t1\n");
	fprintf(f ,"\t_operando_1\tresw\t1\n");
	fprintf(f ,"\t_operando_2 resw\t1\n");
	fprintf(f ,"\n");
	fprintf(f ,"segment .text\n");
	fprintf(f ,"\tglobal main\n");
	fprintf(f ,"\textern print_string, print_endofline, print_int\n");
	fprintf(f ,"\textern scan_int\n");
	fprintf(f ,"\n");
	fprintf(f ,"main:\n");
	fprintf(f ,"\tmov dword [__esp] , esp\n");
	fprintf(f ,"\n");
	fprintf(f ,"menu:\n");
	fprintf(f ,"\tpush dword _string_1\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\tcall print_endofline\n");
	fprintf(f ,"\t\n");
	fprintf(f ,"\tpush dword _string_2\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tpush dword _option\n");
	fprintf(f ,"\tcall scan_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\tpush dword [_option]\n");
	fprintf(f ,"\t\n");
	fprintf(f ,"\tpop eax\n");
	fprintf(f ,"\tcmp eax, 1\n");
	fprintf(f ,"\tje resta\n");
	fprintf(f ,"\tcmp eax, 2\n");
	fprintf(f ,"\tje multiplic\n");
	fprintf(f ,"\tcmp eax, 3\n");
	fprintf(f ,"\tje pot\n");
	fprintf(f ,"\tcmp eax, 4\n");
	fprintf(f ,"\tje quit\n");
	fprintf(f ,"\tcall menu\n");
	fprintf(f ,"\n");
	fprintf(f ,"resta:\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tmov dword [_operando_1], %d\n", atoi(argv[2]));
	fprintf(f ,"\tpush dword [_operando_1]\n");
	fprintf(f ,"\tpop dword ebx\n");
	fprintf(f ,"\tpush dword [_operando_1]\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tpush dword _resta\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tmov dword [_operando_2], %d\n", atoi(argv[3]));
	fprintf(f ,"\tpush dword [_operando_2]\n");
	fprintf(f ,"\tpop dword ecx\n");
	fprintf(f ,"\tpush dword [_operando_2]\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tpush dword _igual\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tsub ebx, ecx\n");
	fprintf(f ,"\tpush dword ebx\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\tcall print_endofline\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tcall menu\n");
	fprintf(f ,"\n");
	fprintf(f ,"multiplic:\n");
	fprintf(f ,"\tmov dword [_operando_1], %d\n", atoi(argv[2]));
	fprintf(f ,"\tpush dword [_operando_1]\n");
	fprintf(f ,"\tpop dword ebx\n");
	fprintf(f ,"\tpush dword [_operando_1]\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tpush dword _multiplicar\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tmov dword [_operando_2], %d\n", atoi(argv[3]));
	fprintf(f ,"\tpush dword [_operando_2]\n");
	fprintf(f ,"\tpop dword ecx\n");
	fprintf(f ,"\tpush dword [_operando_2]\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tpush dword _igual\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tmov eax, ebx\n");
	fprintf(f ,"\timul ecx\n");
	fprintf(f ,"\tpush dword eax\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\tcall print_endofline\n");
	fprintf(f ,"\tcall menu\n");
	fprintf(f ,"\n");
	fprintf(f ,"pot:\n");
	fprintf(f ,"\tmov dword [_operando_1], %d\n", atoi(argv[2]));
	fprintf(f ,"\tpush dword [_operando_1]\n");
	fprintf(f ,"\tpop dword ebx\n");
	fprintf(f ,"\tpush dword [_operando_1]\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tpush dword _multiplicar\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tmov dword [_operando_1], %d\n", atoi(argv[2]));
	fprintf(f ,"\tpush dword [_operando_1]\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tpush dword _igual\n");
	fprintf(f ,"\tcall print_string\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\n");
	fprintf(f ,"\tmov eax, ebx\n");
	fprintf(f ,"\timul ebx\n");
	fprintf(f ,"\tpush dword eax\n");
	fprintf(f ,"\tcall print_int\n");
	fprintf(f ,"\tadd esp, 4\n");
	fprintf(f ,"\tcall print_endofline\n");
	fprintf(f ,"\tcall menu\n");
	fprintf(f ,"quit:\n");
	fprintf(f ,"\tmov dword esp, [__esp]\n");
	fprintf(f ,"\tret\n");

return 0;
}