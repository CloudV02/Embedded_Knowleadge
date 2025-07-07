// kiến thức cần xem lại function pointer, union tối ưu bộ nhớ

#include "module_manager.h"
#include "bitmask_utils.h"

int main()
{
	Module_Union * list = (Module_Union *)malloc(sizeof(Module_Union));
	
	/*data user transmit*/
	Module_Union Motor = {.id = 12345, .name = "Motor", .status = STATUS_ON, .permission = PREMISSION_READ, };
	Module_Union ABS = {.id = 12346, .name = "ABS", .status = STATUS_ON, .permission = PREMISSION_READ,};
	Module_Union Light = {.id = 12347, .name = "Light"};
	Module_Union DieuHoa = {.id = 12348,.name = "DieuHoa"};
	Module_Union SenSor_Temp = {.id = 123,.name = "SenSor_Temp"};
	Module_Union SenSor_H = {.id = 156,.name = "SenSor_H"};
	
	// test add 
	add_module(&Motor, list);
	add_module(&ABS, list);
	add_module(&Light, list);
	add_module(&DieuHoa, list);
	add_module(&SenSor_Temp, list);
	add_module(&SenSor_H, list);
	
	// test del
	del_module(&ABS,list);
	del_module(&SenSor_H,list);
	
	// test check status module motor
	Motor.status = STATUS_OFF;
	
	check_sModule(Motor);
	
	//test check permission module motor
	check_perModule(Motor);
	int loop;
	for(loop = 0; loop < number_of_module; loop++)
	{
		printf("%d %s\n",list[loop].id,list[loop].name);
	}
	
	free(list);
}