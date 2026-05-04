# include<bits/stdc++.h>

using namespace std;


bool isVaild(int a , int b , int c , int d){
    int r_a = 0;
    int r_b = 0;
    int r_c = 0;
    string str_a = to_string(a);
    string str_b = to_string(b);
    string str_c = to_string(c);
    int a_len = str_a.length();
    int b_len = str_b.length();
    int c_len = str_c.length();

    for (int i = c_len - 1; i >= 0; i--){
        if (str_c[i] - '0' >= d){
            return false;
        }
        r_c += (str_c[i] - '0') * pow(d , c_len - 1 - i);
    }

    for (int i = a_len - 1; i >= 0; i--){
        if (str_a[i] - '0' >= d){
            return false;
        }
        r_a += (str_a[i] - '0') * pow(d , a_len - 1 - i);
    }

    for (int i = b_len - 1; i >= 0; i--){
        if (str_b[i] - '0' >= d){
            return false;
        }
        r_b += (str_b[i] - '0') * pow(d , b_len - 1 - i);
    }

    if (r_a * r_b == r_c){
        return true;
    }
    return false;
    
}

int min_ans(int a , int b , int c){
    int r = 2;
    while (r < 17){
        if (isVaild(a , b , c , r)){
            return r;
        }
        r++;
    }
    return 0;
}


int main(){
    int T;
    cin >> T;
    while (T--){
    int a , b , c;
    cin >> a >> b >> c;

    cout << min_ans(a , b , c) << endl;
    }
    return 0;
}
