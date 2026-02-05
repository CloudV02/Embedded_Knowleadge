/*
    char *c_fullName;
    uint16_t u16_age;
    char *c_address;
    long l_numberPhone;
*/
//void findInfor(c_fullName,u16_age,c_address,l_numberPhone);

#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct InfoMember{
    char *c_fullName;
    int u16_age;
    char *c_address;
    int l_numberPhone;
}InfoMember;




#endif