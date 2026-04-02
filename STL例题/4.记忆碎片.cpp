# include<bits/stdc++.h>
using namespace std;

int main(){
    map<string , int> m;
    int Q;
    cin >> Q;
    for (int i = 1 ; i <= Q ; i++){
        int op , x;
        string s;
        cin >> op >> s ;
        if (op == 1){
            cin >> x;
            m[s] += x;
        }
        
        else if (op == 2){
            cin >> x;
            auto it = m.find(s);
            if (it != m.end()){
                if (it->second >= x){
                    it->second -= x;
                    cout << it->second << endl;
                }
                else{
                    cout << -1 << endl;
                }
            }
            else{
                cout << -1 << endl;
            }
        }

        else if (op == 3){
            auto it = m.find(s);
            if (it != m.end()){
                cout << it->second << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}