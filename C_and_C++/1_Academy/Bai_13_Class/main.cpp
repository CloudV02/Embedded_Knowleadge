#include <iostream>
#include <string>
using namespace std;

/* ban chat la 1 kieu du lieu */
/* co pham vi truy cap*/
class SinhVien{
    /* member co the la ham, bien, mang .., class ban chat giong nhu 1 file co ham co mang, co the dinh nghia cac kieu du lieu */
    public:
        SinhVien(string ten, string lop);         // conductor
        void display();     // method - phương thức
        static int Test;
    /* nhung member nam trong private thi object khong dung toi dc, no chi co gia tri tai class */
    private:
        int ID ;             // property - thuộc tính
        string TEN;
        string LOP;
};

int SinhVien::Test = 10;

void SinhVien::display(){     // method
            cout<<"MSV: "<<ID<<endl;
            cout<<"TEN: "<<TEN<<endl;
            cout<<"LOP: "<<LOP<<endl;
}

SinhVien::SinhVien(string ten, string lop){
    ID = 100;
    TEN = ten;
    LOP = lop;
}
int main()
{
    /* string la 1 kieu du lieu thao tac voi chuoi */

    //SinhVien sv; // class - object

    SinhVien sv("Lam","KTMT"), sv1("Dung","VHTT");
    sv.display();

    printf("%d\n",&sv.Test);
    printf("%d\n",&sv1.Test);
}

/* static trong class  */