#include "../header/main.h"
#include "../header/node.h"
#include "../header/file.h"
extern Node_Member *HEAD_Node;

void dataInfo()
{
    InfoMember inforMember = {
        .c_address = "VietNam",
        .c_fullName = "LePhucLam",
        .l_numberPhone = 2157812,
        .u16_age = 20
    };
    InfoMember inforMember1 = {
        .c_address = "HaNoi",
        .c_fullName = "adasf",
        .l_numberPhone = 747812,
        .u16_age = 10
    };
    InfoMember inforMember2 = {
        .c_address = "HaiDuong",
        .c_fullName = "dtad",
        .l_numberPhone = 1518,
        .u16_age = 9
    };
    InfoMember inforMember3 = {
        .c_address = "DongNai",
        .c_fullName = "tute",
        .l_numberPhone = 7841,
        .u16_age = 21
    };
    InfoMember inforMember4 ={
        .c_address = "PhuTho",
        .c_fullName = "like",
        .l_numberPhone = 2533,
        .u16_age = 10
    };
    New_Node(inforMember);
    New_Node(inforMember1);
    New_Node(inforMember2);
    New_Node(inforMember3);
    New_Node(inforMember4);

}

int main(){
    dataInfo();
    beginFile();
    inputData();
}