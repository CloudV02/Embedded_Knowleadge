#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    protected:
        int ID;
        string TEN;

    public:
        DoiTuong();
        void Input(string ten);
        void display();
};

DoiTuong::DoiTuong(){
    static int id = 100;
    ID = id;
    id++;
}

void DoiTuong::Input(string ten){
    TEN = ten;
}

void DoiTuong::display(){
    cout << "ID: "<< ID << endl;
    cout << "NAME: "<< TEN << endl;
}


class SinhVien : public DoiTuong{
    private:
        string LOP;
        string HOCKY;
    public:
        void Input(string ten, string lop, string hocky);
        void display();
};

void SinhVien::Input(string ten, string lop, string hocky){
    TEN = ten;
    LOP = lop;
    HOCKY = hocky;
}
void SinhVien::display(){
    cout << "ID: "<< ID << endl;
    cout << "NAME: "<< TEN << endl;
    cout << "CLASS: "<< LOP << endl;
    cout << "HOC KY: "<< HOCKY << endl;
}

int main()
{
    DoiTuong dt;
    dt.Input("Lam");
    dt.display();

    SinhVien sv;
    sv.Input("Hoang","CoKhi","HK3");
    sv.display();
}