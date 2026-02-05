#include <iostream>
#include <list>

using namespace std;

enum Gioi_Tinh{
    NAM,
    NU
}GT;

enum QUANLY{
    THOAT = 0,
    THEM,
    SUA,
    XOA,
    TIM,
    SX,
    IN,
    LUU,
}QL;

class Thong_Tin
{
    public:
        Thong_Tin();
        int id;
        string ten;
        int tuoi;
        string gioi_tinh;
        float diem_Toan;
        float diem_Ly;
        float diem_Hoa;
        float diemTB();
};
Thong_Tin::Thong_Tin(){
    static int i = 202401;
    id = i;
    i++;
}
float Thong_Tin::diemTB(){
    return (diem_Toan+diem_Ly+diem_Hoa)/3;
}


list<class Thong_Tin> array_SV;

void menu();
void Add_SV();
void Fix_SV();
void Delete_SV();
void Find_SV();
void Arrange_SV();
void In_SV();
//void Save_SV();
void XepLoai_SV(class Thong_Tin New_Sv);

int main()
{
    menu();
}

void menu(){

    int choose = 0;

    while (1)
    {   
        cout << "----QUAN LY SINH VIEN-----" << endl;
        cout << "1. Them sinh vien "<< endl;
        cout << "2. Sua thong tin sinh vien "<< endl;
        cout << "3. Xoa sinh vien "<< endl;
        cout << "4. Tim kiem sinh vien " << endl;
        cout << "5. Sap xep sinh vien " << endl;
        cout << "6. In ra danh sach sinh vien "<< endl;
        cout << "7. Luu vao file \"database_sv.csv\""<<endl;
        cout << "0. Thoat" << endl;
        do
        {
            if(choose > 7){
                cout << "Chon lai"<< endl;
            }
            cout << "Vui long chon chuc nang: "; cin >> choose;

            switch (choose)
            {
            case THOAT:
                return;
                break;
            case THEM:
                Add_SV();
                break;
            case SUA:
                Fix_SV();
                break;
            case XOA:
                Delete_SV();
                break;
            case TIM:
                Find_SV();
                break;
            case SX:
                Arrange_SV();
                break;
            case IN:
                In_SV();
                break;
            case LUU:
                //Save_SV();
                break;
            }
            
        } while (choose > 7);
    }

}
void XepLoai_SV(class Thong_Tin New_Sv){
    if (New_Sv.diemTB() < 5)
    {
        cout << "Loai: Yeu" << endl;
    }
    else if (5 <= New_Sv.diemTB() &&  New_Sv.diemTB() < 6.5 )
    {
        cout << "Loai: TB" << endl;
    }
    else if (6.5 <= New_Sv.diemTB() && New_Sv.diemTB() < 8 )
    {
        cout << "Loai: Kha" << endl;
    }
    else{
        cout << "Loai: Gioi" << endl;
    }
}

void Add_SV(){

    int choose;

    class Thong_Tin New_Sv;
    cout << "Nhap ten: "; cin >> New_Sv.ten;
    cout << "Nhap tuoi: "; cin >> New_Sv.tuoi;
    cout << "Gioi tinh: "; cin >> New_Sv.gioi_tinh;
    do{
        cout << "Nhap diem toan: "; cin >> New_Sv.diem_Toan;
        cout << "Nhap diem ly: "; cin >> New_Sv.diem_Ly;
        cout << "Nhap diem hoa: "; cin >> New_Sv.diem_Hoa;
        if(0 > New_Sv.diem_Toan || New_Sv.diem_Toan > 10 || 0 > New_Sv.diem_Ly || New_Sv.diem_Ly >10 || 0 > New_Sv.diem_Hoa || New_Sv.diem_Hoa  > 10){
            cout << "Nhap sai diem, vui long nhap lai"<<endl;
        }
    }while (0 > New_Sv.diem_Toan || New_Sv.diem_Toan > 10 || 0 > New_Sv.diem_Ly || New_Sv.diem_Ly >10 || 0 > New_Sv.diem_Hoa || New_Sv.diem_Hoa  > 10);
    
    
    array_SV.push_back(New_Sv);

    cout << "-----------------------" << endl;
    cout << "ID: "<<New_Sv.id<<endl;
    cout << "Ten: "<< New_Sv.ten << endl;
    cout << "Tuoi: "<< New_Sv.tuoi << endl;
    cout << "Gioi tinh: " << New_Sv.gioi_tinh << endl;
    cout << "Toan"<< "|    Ly     |" << "Hoa" << endl;
    cout << New_Sv.diem_Toan <<"        "<<New_Sv.diem_Ly << "        " << New_Sv.diem_Hoa << endl;
    cout << "Diem trung binh: " << New_Sv.diemTB() << endl;

    XepLoai_SV(New_Sv);
    cout << "1. Them 1 sinh vien khac" << endl;
    cout << "0. Quay lai" << endl;

    cout << "Vui long chon chuc nang ADD_SV: " ; cin >> choose;
    switch (choose)
    {
    case 1:
        Add_SV();
        break;
    
    case 0:
        break;
    }
}

void In_SV(){
    int count = 1;

    list<class Thong_Tin> ::iterator it;
    for(it = array_SV.begin(); it != array_SV.end();it++){
        cout<<"------SINH VIEN THU "<<count<<"------"<<endl;
        cout<<"ID: "<<(*it).id<<endl;
        cout<<"Ten: "<<(*it).ten<<endl;
        cout<<"Tuoi: "<<(*it).tuoi<<endl;
        cout<<"Gioi tinh: "<<(*it).gioi_tinh<< endl;
        cout << "Toan"<< "|    Ly     |" << "Hoa" << endl;
        cout << (*it).diem_Toan <<"        "<<(*it).diem_Ly << "        " << (*it).diem_Hoa << endl;
        cout << "Diem trung binh: " << ((*it).diem_Toan+(*it).diem_Ly+(*it).diem_Hoa)/3 << endl;
        XepLoai_SV(*it);
        count++;
    }
}

void Fix_SV(){
    string name_sv;
    int stt = 1;
    int id_sv;
    int choose;
    list<class Thong_Tin> ::iterator it;

    cout << "   "<<"Sua thong tin sinh vien"<<endl;
    cout <<"Nhap ten sinh vien: ";  cin>>name_sv;
    cout <<"-------------"<<endl;
    cout <<"STT     |    ID      |     TEN"<<endl;
    for(it = array_SV.begin(); it != array_SV.end(); it++){
        if(name_sv == (*it).ten){
            cout<<stt<<"     |    "<<(*it).id<<"      |     "<<(*it).ten<<endl;
        stt++;
        }
    }

    cout <<"Vui long nhap ID sinh vien muon sua thong tin: "; cin>>id_sv;
    for(it = array_SV.begin(); it != array_SV.end(); it++){
        if(id_sv==(*it).id && (*it).ten == name_sv){
            cout<<"ID: "<<(*it).id<<endl;
            cout<<"Ten: "<<(*it).ten<<endl;
            cout<<"Tuoi: "<<(*it).tuoi<<endl;
            cout<<"Gioi tinh: "<<(*it).gioi_tinh<< endl;
            cout << "Toan"<< "|    Ly     |" << "Hoa" << endl;
            cout << (*it).diem_Toan <<"        "<<(*it).diem_Ly << "        " << (*it).diem_Hoa << endl;
            cout << "Diem trung binh: " << ((*it).diem_Toan+(*it).diem_Ly+(*it).diem_Hoa)/3<< endl;
            XepLoai_SV(*it);
            do{
                cout<<"1. Sua ten"<<endl;
                cout<<"2. Sua tuoi"<<endl;
                cout<<"3. Sua gioi tinh"<<endl;
                cout<<"4. Sua diem toan"<<endl;
                cout<<"5. Sua diem ly"<<endl;
                cout<<"6. Sua diem hoa"<<endl;
                cout<<"0. Quay lai"<<endl;

                cout <<"Vui long chon chuc nang: "; cin>>choose;

                switch (choose)
                {
                case 0:
                    
                    break;
                case 1:
                    cout<<"     Sua ten     "<<endl;
                    cout<<"Vui long nhap ten: "; cin>>(*it).ten;
                    
                    break;
                case 2:
                    cout<<"     Sua tuoi     "<<endl;
                    cout<<"Vui long nhap tuoi: "; cin>>(*it).tuoi;
                    
                    break;
                case 3:
                    cout<<"    Sua gioi tinh    "<<endl;
                    cout<<"Vui long nhap gioi tinh: "; cin>>(*it).gioi_tinh;
                    
                    break;
                case 4:
                    cout<<"    Sua diem toan    "<<endl;
                    cout<<"Vui long nhap diem toan: "; cin>>(*it).diem_Toan;
                    break;
                case 5:
                    cout<<"    Sua diem ly     "<<endl;
                    cout<<"Vui long nhap diem ly: "; cin>>(*it).diem_Ly;
                    break;
                case 6:
                    cout<<"    Sua diem hoa    "<<endl;
                    cout<<"Vui long nhap diem hoa: "; cin>>(*it).diem_Hoa;
                    break;
                }
                cout<<"----------"<<endl;
                cout<<"Cap nhat thong tin thanh cong"<<endl;
                cout<<"1. Quay lai"<<endl;
                cout<<"0. Thoat"<<endl;
                cout <<"Nhap: "; cin>>choose;
                if(choose == 0){
                    break;
                }
            }while(choose <7);
        }
    }
}
void Delete_SV(){
    string name_sv;
    int stt = 1;
    int id_sv;
    int choose;
    //int save_inf[];
    list<class Thong_Tin> ::iterator it;

    do {
        cout << "   "<<"Xoa thong tin sinh vien"<<endl;
        cout <<"Nhap ten sinh vien: ";  cin>>name_sv;
        cout <<"-------------"<<endl;
        cout <<"STT     |    ID      |     TEN"<<endl;
        for(it = array_SV.begin(); it != array_SV.end(); it++){
            if(name_sv == (*it).ten){
                cout<<stt<<"     |    "<<(*it).id<<"      |     "<<(*it).ten<<endl;
                //save_inf[stt-1] = (*it).id;
            stt++;
            }
        }

        cout << "Vui long nhap ID sinh vien muon xoa: "<<endl;
        cin >> id_sv;
        for(it = array_SV.begin(); it != array_SV.end(); it++){
            if((*it).id == id_sv && (*it).ten == name_sv){
                array_SV.erase(it);
                cout << "------------"<<endl;
                cout << "Xoa thanh cong"<<endl;
                break;
            }
            
        }
        cout<<"1. Xoa them sinh vien khac "<<endl;
        cout<<"0. Quay lai"<<endl;
        cout << "Vui long chon chuc nang: "; cin>>choose;
        if(choose == 0){
            break;
        }
    }while(choose <2);

}
void Find_SV(){
    int choose;
    string name_sv;
    int id_sv;
    list<class Thong_Tin> ::iterator it;
    int stt = 1;
    do{
        stt = 1;
        cout << "      Tim kiem sinh vien"<<endl;
        cout << "1. Tim kiem theo ten"<<endl;
        cout << "2. Tim kiem theo ID"<<endl;
        cout << "0. Quay lai"<<endl;

        cout << "Vui long chon chuc nang: "; cin>> choose;
        if (choose == 1)
        {
            cout << "      Tim kiem theo ten"<<endl;
            cout << "Nhap ten sinh vien: "; cin>>name_sv;
            cout << "------------"<< endl;
            cout <<"STT |     ID      |     Ten     |     GioiTinh     |    DiemTrungBinh   |   Xeploai "<<endl;
            for(it = array_SV.begin(); it != array_SV.end(); it++){
                if(name_sv == (*it).ten)
                {
                cout<<stt<<" |     "<<(*it).id<<"      |     "<<(*it).ten<<"     |     "<<(*it).gioi_tinh<<"     |    "<<((*it).diem_Toan+(*it).diem_Ly+(*it).diem_Hoa)/3<<endl;
                stt++;
                }
            }
        }
        if (choose == 2)
        {
            cout << "      Tim kiem theo ten"<<endl;
            cout << "Nhap id sinh vien: "; cin>>id_sv;
            cout << "------------"<< endl;
            cout <<"STT |     ID      |     Ten     |     GioiTinh     |    DiemTrungBinh   |   Xeploai "<<endl;
            for(it = array_SV.begin(); it != array_SV.end(); it++){
                if(id_sv == (*it).id)
                cout<<stt<<" |     "<<(*it).id<<"      |     "<<(*it).ten<<"     |     "<<(*it).gioi_tinh<<"     |    "<<((*it).diem_Toan+(*it).diem_Ly+(*it).diem_Hoa)/3<<endl;
            }
        }
        if  (choose == 0){
            break;
        }
        cout << "1. Tim kiem them sinh vien khac" << endl;
        cout << "0. Quay lai"<<endl;
        cout << "Nhap chuc nang: ";cin>>choose;
        if  (choose == 0){
            break;
        }
    }while(choose < 3);
}

void Arrange_SV(){
    
}