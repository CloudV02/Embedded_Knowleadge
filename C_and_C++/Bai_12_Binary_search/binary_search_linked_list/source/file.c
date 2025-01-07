#include "../header/file.h"
#include "../header/node.h"


void beginFile(){
    fptr = fopen("data.csv", "w");
    fprintf(fptr, "%s ,%s ,%s ,%s, %c", "Full Name", "Age", "Address", "Phone Number",'\n');

}

void importData(){

}
void inputData(){
    Node_Member *ptr = HEAD_Node;

    while (ptr->next_Node != NULL)
    {
        fprintf(fptr, "%s ,%d ,%s ,%d ,%c",ptr->dataMember.c_fullName,ptr->dataMember.u16_age, ptr->dataMember.c_address, ptr->dataMember.l_numberPhone,'\n');
        ptr = ptr->next_Node;
    }
    
   fclose(fptr);
}