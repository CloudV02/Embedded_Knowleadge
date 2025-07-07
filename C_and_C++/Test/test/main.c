#include <stdio.h>

void Tong(int a, int b){
	
	printf("%d",a+b);

}

int main()
{
	void (*ptr_func)(int,int);
	
	ptr_func = Tong;
	
	ptr_func(5,7);
	
	
}

