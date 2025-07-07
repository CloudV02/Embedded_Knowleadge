#ifndef __MOD_MAN__
#define __MOD_MAN__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
	{
		int id;
		char *name;
		int status; // ON/OFF
		int permission;	// READ/WRITE/NONE
		int control; // mean call function to practice this functon for action control
}Module_Union;

/*Danh sach cap phat dong cho danh sach Module*/
extern int number_of_module;


void add_module(Module_Union *New_Module, Module_Union * list_var);
void del_module(Module_Union *Del_Module, Module_Union * list_var);
void check_sModule(const Module_Union c_sModule);
void check_perModule(const Module_Union c_pModule);


#endif