#include "nasm.h"

#define VAR_SIZE 64

void openFile(char *name) 
{
	f = fopen(name, "w");
}

void segmentData(){

	fprintf(f, "segment .data\n");
}

void constInt(char *name, int value){

	char newname[VAR_SIZE] = "_";
	strcat(newname, name);

	fprintf(f, "%s\tdw\t%d\n", newname, value);
}

void constString(char* name, char* value){

	char newname[VAR_SIZE] = "_";
	strcat(newname, name);

	fprintf(f, "%s\tdb\t'%s', 0\n", newname, value);
}

void segmentBss(){

	fprintf(f, "segment .bss\n");
	fprintf(f, "__esp\tresd\t1\n");
}

void variable(char* name, int size){

	char newname[VAR_SIZE] = "_";
	strcat(newname, name);

	fprintf(f, "%s\tresw\t%d\n", newname, size);
}

void segmentText(){

	fprintf(f, "segment .text\n");
	fprintf(f, "global main\n");
	fprintf(f, "extern print_string, print_endofline, print_int, print_blank, print_boolean, scan_int, scan_boolean\n");
}

void startProgram(){

	fprintf(f, "main:\n");
	fprintf(f, "mov dword [__esp], esp\n");
}

void instruction(char* line){

	fprintf(f, "%s\n", line);
}

void instructions(int n, char* lines[]){

	int i;

	for(i = 0; i < n; i++){
		instruction(lines[i]);
	}
}

void subrutine(char* name, int n, char* lines[], char* go){

	char newname[VAR_SIZE] = "_";
	strcat(newname, name);

	fprintf(f, "%s:\n", newname);
	instructions(n, lines);
	if(!go)
		fprintf(f, "ret\n");
	else
		call(go);
}

void call(char* name){

	char newname[VAR_SIZE] = "_";
	strcat(newname, name);

	fprintf(f, "call %s\n", newname);
}

void IF(char* var1, char* oper, char* var2, char* callThen, char* callElse, char* go){

	char newvar1[VAR_SIZE] = "_";
	strcat(newvar1, var1);
	
	char newvar2[VAR_SIZE] = "_";
	strcat(newvar2, var2);

	fprintf(f, "mov dword eax, [%s]\n", newvar1);
	fprintf(f, "mov dword ebx, [%s]\n", newvar2);
	fprintf(f, "cmp eax, ebx\n");
	fprintf(f, "%s true\n", oper);
	call(callElse);
	call(go);
	fprintf(f, "true: \n");
	call(callThen);
	call(go);
}

void scan(char *type, char *var){
	
	char newvar[VAR_SIZE] = "_";
	strcat(newvar, var);

	if(strcmp(type, "int") == 0) {
		fprintf(f, "push dword %s\n", newvar);
		fprintf(f, "call scan_int\n");
		fprintf(f, "add esp, 4\n");
	}
}

void print(char *type, char *var){
	
	if(strcmp(type, "int") == 0) {
		fprintf(f, "push dword [%s]\n", var);
		fprintf(f, "call print_int\n");
		fprintf(f, "add esp, 4\n");
	}
	else if(strcmp(type, "string") == 0){
		fprintf(f, "push dword %s\n", var);
		fprintf(f, "call print_string\n");
		fprintf(f, "add esp, 4\n");
	}
}

void quit(){

	fprintf(f, "mov dword esp, [__esp]\n");
	fprintf(f, "ret\n");
}