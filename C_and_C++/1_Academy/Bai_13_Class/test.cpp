#include <iostream>
#include <set>

using namespace std;

int main(){

	set<int> s;
	int n;
	int x;
	cout<<"Nhap so phan tu: ";cin>>n;

	/* Nhap */
	for (int i = 0; i < n; i++)
	{
		cout<<"Nhap: ";cin>>x;
		s.insert(x);
	}
	for(int p: s){
		cout << p <<" ";
	}

	/* check so luong phan tu */
	cout<<endl;
	cout<<"So luong phan tu khac nhau: "<<s.size()<<endl;
	
	/* tim kiem phan tu */
	int find;
	cout<<"Phan tu can tim: ";cin>>find;
	auto it = s.find(find);
	if(*it == find){
		cout<<"Tim thay phan tu can tim la: "<<*it<<endl;
	}
	else{
		cout<<"Khong tim thay"<<endl;
	}
	
	/*In ra nguoc day */
	cout<<"In nguoc: ";
	for(auto it = s.rbegin(); it != s.rend();it++){
		cout << *it <<" ";
	}
	cout<<endl;


}