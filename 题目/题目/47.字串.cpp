# include<bits/stdc++.h>
using namespace std;

bool find(string a , vector<string> b){
    string rev = a;
    reverse(rev.begin() , rev.end());
    for (const auto& s : b) {
        if (s.find(a) == string::npos && s.find(rev) == string::npos) {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    string p = strings[0];
    int p_len = p.size();

    for (int len = p_len; len > 0; len--) {
        for (int start = 0; start + len <= p_len; start++) {
            string sub = p.substr(start, len);
            if (find(sub, strings)) {
                cout << len << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
