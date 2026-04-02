# include<iostream>
using namespace std;


int a_num[256] = {0};
int b_num[256] = {0};
int c_num[256] = {0};

int main(){
    string a;
    string b;
    cin >> a;
    cin >> b;
    int k = 255;
    for (int i = a.length() - 1 ; i >= 0 ; i--){
        a_num[k] = a[i]-'0';
        k--;
    } 
    
    k = 255;
    for (int i = b.length() - 1 ; i >= 0 ; i--){
        b_num[k] = b[i]-'0';
        k--;
    } 

    int temp = 0;
    for (int i = 255 ; i >= 0 ; i--){
        int t = a_num[i] + b_num[i] + temp;
        c_num[i] = t % 10;
        temp = t / 10;
    }

    int p = 0;
    for (int i = 0 ; i < 256 ; i++){
        if (c_num[i] != 0){
            p = i;
            break;
        }
    }

    for (int i = p ; i < 256 ; i++){
        cout << c_num[i] << "";
    }

    return 0;
}