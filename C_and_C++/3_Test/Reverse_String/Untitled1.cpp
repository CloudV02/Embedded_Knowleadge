#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char* daoNguocTen(const char* ten) {
    // Sao chép chu?i g?c ð? không làm thay ð?i d? li?u ð?u vào
    char* buffer = new char[strlen(ten) + 1];
    strcpy(buffer, ten);

    // Tách các t? và lýu vào m?ng con tr?
    char** cacTu = new char*[100]; // Gi? s? t?i ða 100 t?
    int soTu = 0;
    char* tu = strtok(buffer, " ");
    
    while (tu != nullptr) {
        cacTu[soTu] = new char[strlen(tu) + 1];
        strcpy(cacTu[soTu], tu);
        soTu++;
        tu = strtok(nullptr, " ");
    }

    // Ð?o ngý?c m?ng các t?
    reverse(cacTu, cacTu + soTu);

    // Ghép các t? ð? ð?o ngý?c thành chu?i m?i
    char* ketQua = new char[strlen(ten) + 1];
    ketQua[0] = '\0'; // Kh?i t?o chu?i r?ng

    for (int i = 0; i < soTu; ++i) {
        strcat(ketQua, cacTu[i]);
        if (i != soTu - 1) {
            strcat(ketQua, " ");
        }
        delete[] cacTu[i]; // Gi?i phóng t?ng t?
    }

    // D?n d?p b? nh?
    delete[] buffer;
    delete[] cacTu;

    return ketQua;
}

int main() {
    const char* ten = "Lê Phúc Lâm";
    char* tenDaoNguoc = daoNguocTen(ten);
    cout << "Tên ð?o ngý?c: " << tenDaoNguoc << endl;
    
    delete[] tenDaoNguoc; // Nh? gi?i phóng b? nh? cu?i cùng
    return 0;
}
