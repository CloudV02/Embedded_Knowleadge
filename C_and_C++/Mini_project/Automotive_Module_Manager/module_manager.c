
#include "module_manager.h"
#include "bitmask_utils.h"


int number_of_module = 0;


void add_module(Module_Union *New_Module, Module_Union * list_var)
{
	if(number_of_module == 0){
		*list_var = *New_Module;
	}
	else
	{
		list_var = (Module_Union*)realloc(list_var, (number_of_module+1)*sizeof(Module_Union));
		list_var[number_of_module] = *New_Module;	
	}
	number_of_module = number_of_module + 1;
}

void del_module(Module_Union *Del_Module, Module_Union * list_var)
{
	int loop;
	int loop_2;
	
	if(number_of_module == 0)
	{
		// error
	}
	else if(number_of_module == 1)
	{
		free(list_var);
	}
	else
	{
		for(loop = 0; loop<number_of_module; loop++)
		{
			if(Del_Module->id == list_var[loop].id)
			{
				for(loop_2 = 0; loop_2 < (number_of_module-loop); loop_2++)
				{
					list_var[loop+loop_2] = list_var[loop+loop_2+1];
				}
			}
		}
		number_of_module = number_of_module - 1;
		list_var = (Module_Union*)realloc(list_var,(sizeof(Module_Union))*(number_of_module));
	}
}

void check_sModule(const Module_Union c_sModule)
{
	if(c_sModule.status == (int)(STATUS_ON))
	{
		printf("%s is on\n",c_sModule.name);
	}
	else if(c_sModule.status == (int)(STATUS_OFF))
	{
		printf("%s is off\n",c_sModule.name);
	}
	else
	{
		printf("%s is warning\n",c_sModule.name);
	}
}

void check_perModule(const Module_Union c_pModule)
{
	if(c_pModule.permission == (int)(PREMISSION_READ))
	{
		printf("%s can read\n",c_pModule.name);
	}
	else if(c_pModule.permission == (int)(PREMISSION_WRITE))
	{
		printf("%s can write\n",c_pModule.name);
	}
	else
	{
		printf("%s none\n",c_pModule.name);
	}
}

