# include<bits/stdc++.h>
using namespace std;

int Getmin_max(vector<int> A , vector<int> B){
    int ans = 0;

    for (int x : A){
        auto it = lower_bound(B.begin() , B.end() , x);
        int current_min = INT_MAX;

        if (it != B.end()){
            current_min = min(current_min , *it-x);
        }

        if (it != B.begin()){
            current_min = min(current_min , x - *(--it));
        }

        ans = max(ans , current_min);
    }

    return ans;
}


int main(){
    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<int> A(M), B(N);
    for (int i = 0; i < M; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 结果是：A 找 B 的最大最小差值 与 B 找 A 的最大最小差值 中的较大者
    int resA = Getmin_max(A, B);
    int resB = Getmin_max(B, A);

    cout << max(resA, resB) << endl;

    return 0;

}