#include <iostream>
#include <string>
using namespace std;
class Display{
    public:
        char *word(){
            return (char*)"Class Display\n";
        }
        void display(){
            printf("Test: %s\n",word());
        }
};
class Child : public Display{
    public:
        char *word(){
            return (char*)"Class Child\n";
        }
};
int main(){
    Display ds;
    Child cd;

    ds.display();   
    cd.display();
}
