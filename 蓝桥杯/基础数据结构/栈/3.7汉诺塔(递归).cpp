#include<bits/stdc++.h>
using namespace std;
int sum = 0;
void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << a << " -> " << c << endl;
        sum++;
        return;
    }
    hanoi(n-1, a, c, b);
    cout << a << " -> " << c << endl;sum++;
    hanoi(n-1, b, a, c);
}


int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << sum << endl;
    return 0;
}