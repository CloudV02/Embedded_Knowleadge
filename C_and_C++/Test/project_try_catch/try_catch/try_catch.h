#ifndef __LIB_TRY__
#define __LIB_TRY__

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_state = 0;

#define TRY		exception_state = setjmp(buf)\
				if(exception_state == setjmp(buf))
#define CATCH(x)	if(exception_state == x)
#define THROW(x)	longjmp(buf,x)




#endif