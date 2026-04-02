#include<iostream>

using namespace std;

int main()
{
    string a;
    string *str = &a;
    *str = "Hello error";
    cout << *str << endl;
    return 0;
}