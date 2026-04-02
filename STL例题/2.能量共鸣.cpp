# include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    int Q;
    cin >> Q;
    for (int i = 1 ; i <= Q ; i++){
        int op , x;
        cin >> op >> x;
        if (op == 1){
            s.insert(x);
        }
        else if (op == 2){
            s.erase(x);
        }
        else if (op == 3){
            auto it = s.lower_bound(x);
            if (it == s.end()){
                cout << -1 << endl;
            }
            else{
                cout << *it << endl;
            }
        }
    }
    return 0;
}