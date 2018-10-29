/*
Name: Faizan Ahmad
Creation Date: 28/10/2018
Problem Description: 
    Swap values such that a = b, b = c, c=d, d=e and e = a.

*/
# include <iostream>
using namespace std;

void rotate(int& a, int& b, int& c, int& d, int& e);

int main()
{
    int a, b, c, d, e;
    cout << "Enter five integers:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
    cout << "e = ";
    cin >> e;
    
    cout << "After rotation :" << endl;
    rotate(a, b, c, d, e);
    cout << "a = " << a << "\nb = "<< b 
    << "\nc = " << c << "\nd = " << d 
    << "\ne = " << e << endl;
    return 0;
}

void rotate(int& a, int& b, int& c, int& d, int& e)
{
    int temp = a;
    a = b, b = c, c = d, d = e, e = temp;
    
    return;
}

