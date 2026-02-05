#include <stdio.h>


int main(){
	
	static int b = 100;
	
	static int *a = &b;
	
	printf("%d\n",a);
	
	a++;
	
	printf("%d",a);
}