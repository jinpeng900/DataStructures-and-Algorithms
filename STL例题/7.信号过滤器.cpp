# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N , K;
    cin >> N >> K;
    priority_queue<int> max_pq;
    for (ll i = 0 ; i < N ; ++i){
        int op , x;
        cin >> op >> x;
        if(op == 1){
            if (max_pq.size() < K){
                max_pq.push(x);
            }
            else if (x < max_pq.top()){
                max_pq.pop();
                max_pq.push(x);
            }
        }
        else if (op == 2){
            if (max_pq.size() < K){
                cout << -1 << endl;
            }
            else{
                cout << max_pq.top() << endl;
            }
        }
    }
}