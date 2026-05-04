#include<bits/stdc++.h>

using namespace std;


string convert(string b){
    string h;

    int len = b.size();
    int d = len % 4;
    if(d != 0){
        b = string(4 - d, '0') + b;
    }

    unordered_map<string, char> m{
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };

    for(int i = 0; i < b.size(); i += 4){
        string s = b.substr(i, 4);
        h += m[s];
    }


    return h;
}


int main(){
    string b;
    cin >> b;

    cout << convert(b) << endl;

    return 0;
}