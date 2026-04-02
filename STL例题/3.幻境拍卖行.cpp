# include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> s;
    int Q;
    cin >> Q;
    for (int i = 1 ; i<= Q ; i++){
        int op , x;
        cin >> op >> x;
        if (op == 1){
            s.insert(x);
        }

        else if (op == 2){
            auto it = s.find(x);
            if (it != s.end()){
                s.erase(it);
            }
        }
        else if (op == 3){
            auto it = s.upper_bound(x);
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