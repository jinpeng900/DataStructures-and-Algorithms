#include<bits/stdc++.h>
using namespace std;


string add(string a , string b){
    int a_len = a.size();
    int b_len = b.size();
    string ans;

    int carry = 0;
    int i = a_len - 1;
    int j = b_len - 1;
    while (i >= 0 || j >= 0 || carry) {
        int num_a = (i >= 0) ? (a[i] - '0') : 0;
        int num_b = (j >= 0) ? (b[j] - '0') : 0;
        int sum = num_a + num_b + carry;
        ans += (sum % 10 + '0');
        carry = sum / 10;
        i--;
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


string multiply(string a , string b){
    int a_len = a.size();
    int b_len = b.size();
    
    string ans = "0";

    int i = a_len - 1;
    int j = b_len - 1;
    int p = 0;
    while(j >= 0){
        int carry = 0;
        string temp(p, '0');
        while (i >= 0 || carry) {
            int num_a = (i >= 0) ? (a[i] - '0') : 0;
            int num_b = (j >= 0) ? (b[j] - '0') : 0;
            int sum = num_a * num_b + carry;
            temp += (sum % 10 + '0');
            carry = sum / 10;
            i--;
        }
        reverse(temp.begin(), temp.end());
        ans = add(ans, temp);
        j--;
        p++;
        i = a_len - 1;
    }

    return ans;
}   



int main(){
    int a;
    cin >> a;

    string ans = "1";
    for (int i = 1; i <= a; i++) {
        string temp = to_string(i);
        ans = multiply(ans, temp);
    }
    cout << ans << endl;
}




