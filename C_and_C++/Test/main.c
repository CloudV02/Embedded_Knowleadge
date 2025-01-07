#include <stdio.h>

/*
    char *c_fullName;
    uint16_t u16_age;
    char *c_address;
    long l_numberPhone;
*/
void data_file();
int main(){
 data_file();
}
void data_file()
{
    FILE *ptr = fopen("data.csv","w");

    fprintf(ptr, "%s ,%s ,%s ,%s, %c", "Full Name", "Age", "Address", "Phone Number",'\n');

    fprintf(ptr, "%s ,%d ,%s ,%d ,%c", "Le Phuc Lam", 20,"Ha Noi", 15447, '\n');

    fprintf(ptr, "%s ,%d ,%s ,%d ,%c", "Le Phuc ", 20,"Ha Noi", 1848, '\n');
    fclose(ptr);
}