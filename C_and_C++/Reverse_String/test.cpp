#include <iostream>
#include <sstream>
#include <vector>


using namespace std;
// reverse string -> VD: Xin chao moi nguoi -> nguoi moi chao xin


// step: input string -> doc tung ki tu trong string


vector<uint8_t> TachTen(string sName){
    vector<uint8_t> vTachTen;
    stringstream ss(sName);
    
}

int main()
{
    // problem -> với cách nhập thông thường như cin >> thì sẽ không nhập được khoảng trắng va bi mat du lieu sau dau cach

    std::string sReverse_Name;

    getline(cin,sReverse_Name);

    // Question: Why use getline is done, cin is not, and why cin lại bị mất khoảng trắng
    /* Answer: theo cơ chế hoạt động của cin là tạo 1 luồng để nhập dữ liệu từ bàn phím vào và nó không thể đọc các khoảng trắng như space or newline or tab
    nên do đó người ta mới có getline và nó chỉ kết thúc khi gặp newline "/n" và với input parameter của getline sử dụng cin là vì mình nhập luồng vào từ máy tính
    ngoài luồng nhập từ bàn phím, ta còn có luồng nhập từ tệp tin và ngoài ra còn luồng nhập chuỗi sstream
    - Luồng nhập chuỗi là như nào? Tức là 1 cái chuỗi khi nó được khởi tạo thì 1 kí tự nó sẽ không có 1 địa chỉ riêng như là char mà nó chỉ được cấp 1 cái địa chỉ để đọc cả cái chuỗi đấy và nó là cố định và không thể thay đổi. Nên sinh ra luồng nhập chuỗi và thư viện của nó là sstream là để đọc từng kí tự trong 1 chuỗi.
    */
}