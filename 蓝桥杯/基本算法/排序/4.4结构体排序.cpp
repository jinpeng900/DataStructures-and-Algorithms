#include <bits/stdc++.h>
using namespace std;

struct stu{
    int id;
    int chinese , math , english;
    int sum;
}st[301];


bool cmp(stu a , stu b){
    if (a.sum > b.sum) return true;
    else if (a.sum < b.sum) return false;
    else{
        if (a.chinese > b.chinese) return true;
        else if (a.chinese < b.chinese) return false;
        else{
            if (a.id < b.id) return true;
            else return false;
        }
    }
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        st[i].id = i+1;
        cin >> st[i].chinese >> st[i].math >> st[i].english;
        st[i].sum = st[i].chinese + st[i].math + st[i].english;
    }
    sort(st , st + n , cmp);
    for (int i = 0 ; i < 5 ; i++){
        cout << st[i].id << " " << st[i].sum << endl;
    }
    return 0;
}
