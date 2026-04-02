#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];


int main(){
    int n;
    cin >> n;
    int cnt = 0;
    while(scanf("%d" , &a[cnt]) != EOF){
        cnt++;
    }
    sort(a , a + cnt);
    int c , b;
    for (int i = 1 ; i < cnt ; i++){
        if (a[i] - a[i-1] > 1){
            c = a[i-1] + 1;
        }
        if (a[i] == a[i-1]){
            b = a[i];
        }
    }
    cout << c << " " << b << endl;
    return 0;
}