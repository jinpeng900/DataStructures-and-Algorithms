# include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    
    cin >> T;

    for (int t = 0 ; t < T ; ++t){
        int n;
        cin >> n;
        priority_queue<int , vector<int> , greater<int>>pq;

        for (int i = 0 ; i < n ; i++){
            int p;
            cin >> p;
            pq.push(p);
        }

        long long ans = 0;

        while (pq.size() > 1){
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();

            ans += a+b;
            pq.push(a+b);
        }

        cout << ans << endl;
    }

    return 0;
}