#include <iostream>
#include <vector>

using namespace std;

bool check(int m , int k){
    int pos = 0;
    for (int i = 0 ; i < m ; i++){
        pos = (pos + k - 1) % (2*m - i);

        if (pos < m){
            return false;
        }
    }
    return true;
}



int main(){
    int m;
    cin >> m;
    int k = m+1;
    while (true){
        if (check(m , k)){
            cout << k << endl;
            break;
        }
        k++;
    }
    return 0;
}