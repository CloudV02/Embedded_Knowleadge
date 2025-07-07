#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char* name;

}Test_Struct;

int main(){

    Test_Struct *ptr = (Test_Struct*)malloc(2*sizeof(Test_Struct));

    Test_Struct struct1 = {.id = 666, .name = "Hi"};
    Test_Struct struct2 = {.id = 5};

    *ptr = struct1;

    ptr->id;
}