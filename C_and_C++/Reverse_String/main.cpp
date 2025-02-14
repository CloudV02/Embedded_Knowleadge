#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> tachTen(const string &ten) {
    vector<string> cacTu;
    stringstream ss(ten);
    string tu;
    while (ss >> tu) {
        cacTu.push_back(tu);
    }
    return cacTu;
}

string daoNguocTen(const string &ten) {
    vector<string> cacTu = tachTen(ten);
    reverse(cacTu.begin(), cacTu.end());
    
    if (cacTu.empty()) return "";
    
    string ketQua = cacTu[0];
    for (size_t i = 1; i < cacTu.size(); ++i) {
        ketQua += " " + cacTu[i];
    }
    return ketQua;
}

int main() {
    string ten;
    cout << "Nhập họ tên: ";
    getline(cin, ten);
    
    string tenDaoNguoc = daoNguocTen(ten);
    cout << "Tên đảo ngược: " << tenDaoNguoc << endl;
    
    return 0;
}