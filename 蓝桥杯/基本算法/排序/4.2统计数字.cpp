#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0 ; i < n ; i++)
    {
        cin >> numbers[i];
    }
    sort(numbers , numbers + n);
    int cnt = 0;
    for (int i = 1 ; i < n ; i++){
        cnt++;
        if (numbers[i] != numbers[i - 1])
        {
            cout << numbers[i - 1] << " " << cnt << endl;
            cnt = 0;
        }
    }
     cout << numbers[n - 1] << " " << cnt + 1 << endl;
    return 0;
}
