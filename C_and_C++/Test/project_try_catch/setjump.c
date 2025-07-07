#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
double Func_divide(int number_1, int number_2)
{
	if(number_2 == 0)
	{
		longjmp(buf,1);
	}
	return number_1/(double)(number_2);
}

int main()
{
	int exception_state = setjmp(buf);
	
	if(exception_state == 0)
	{
		printf("Run program !\n");
		printf("%f\n", Func_divide(5,1));
	}
	if(exception_state == 1)
	{
		printf("ERROR divide !\n");
	}
}