# include<bits/stdc++.h>
using namespace std;

int main(){
    queue<pair<string , long long>> q;
    int N , Q;
    cin >> N >> Q;
    for (int i = 1 ; i <= N ; i++){
        pair<string , long long> m;
        string Name;
        long long Time;
        cin >> Name >> Time;
        m = {Name , Time};
        q.push(m);
    }

    long long time = 0;
    
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        if (it.second > Q){
            it.second -= Q;
            time += Q;
            q.push(it);
        }
        else{
            time += it.second;
            cout << it.first << " " << time << endl;
        }
    }



    return 0;    
}