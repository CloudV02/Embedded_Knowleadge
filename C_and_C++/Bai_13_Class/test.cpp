// C++ program to illustrate the
// lvalue and rvalue

#include <iostream>
using namespace std;

// Driver Code
int main()
{
	// Declaring the variable
	int a{ 10 };

	// Declaring reference to
	// already created variable
    int d = 30;
	int& b = a;

    int &&c = 20;
    c =d;

	// Provision made to display
	// the boolean output in the
	// form of True and False
	// instead of 1 and
	cout << boolalpha;

	// Comparing the address of both the
	// variable and its reference and it
	// will turn out to be same
    cout << &a <<endl;
    cout << c << endl;
	cout << (&a == &b) << endl;
	return 0;
}
