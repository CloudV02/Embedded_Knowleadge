#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

#define FUNC  3


int main()
{
#if FUNC == 1
    vector<int> array;

    array.push_back(2);
    array.push_back(3);
    array.push_back(5);
    array.push_back(7);
    array.push_back(3);

    array.pop_back();

    array.insert(array.begin()+2,10);

    array.erase(array.begin());

    array.clear();

    for (size_t i = 0; i < array.size(); i++)
    {
        cout<<"i = "<< array[i] <<endl;
    }

#elif FUNC ==2

    list<int> array_list;
    array_list.push_back(10);
    array_list.push_back(5);
    array_list.push_back(2);
    for(int item : array_list){
        cout<<"i = "<< item << endl;
    }
    list<int> ::iterator it;

    for (it = array_list.begin(); it != array_list.end(); it++)
    {
        cout<<"item = "<<*it<<endl;
    }
    int i = 0;
    for (it = array_list.begin(); it != array_list.end(); it++)
    {
        if(i == 1){
            array_list.insert(it,1616);
        }
        i++;
    }
    for (it = array_list.begin(); it != array_list.end(); it++)
    {
        cout<<"item = "<<*it<<endl;
    }
#elif FUNC == 3

    map<int, string > array;
    array[100] = "Le Phuc Lam";
    array[101] = "Nguyen Thi Thuy Dung";
    array[102] = "hehe";

    for (auto item : array)
    {
        cout<<"key: "<< item.first << ", value: " << item.second << endl;   
    }
    
#endif
}   
