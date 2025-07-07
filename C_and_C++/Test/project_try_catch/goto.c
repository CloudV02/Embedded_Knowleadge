#include <stdio.h>
#define PROGRAM 1

void delay(int time)
{
	int i = 0;
	for(i = 0; i<time; i)
	{
		i++;
	}
}

typedef enum{
	RED,
	YELLOW,
	BLUE
}TRAFFIC_JAME_LIGHT;

int main()
{
	#if PROGRAM == 1
	int i = 0;
	start:
	if(i>5)
	{
		goto end;
	}
	
	printf("%d\n", i);
	i++;
	goto start;
	end:
	
	printf("Ket thuc chuong trinh");
	
	#elif PROGRAM == 2
	TRAFFIC_JAME_LIGHT Current_State;
	while(1)
	{
		switch(Current_State)
		{
		case RED:
			delay(50);
			Current_State = RED;
			goto end;
		case YELLOW:
			delay(10);
			Current_State = YELLOW;
			goto end;
		case BLUE:
			delay(30);
			Current_State = BLUE;
			goto end;
		}
	end:
	}
	
	
	#endif
	
	
}