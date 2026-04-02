#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s_init;
    cin >> s_init;
    
    list<char> board;
    
    // 初始化：将字符加入链表
    if (s_init != "EMPTY") {
        for (char c : s_init) {
            board.push_back(c);
        }
    }
    else{

    }
    
    // 光标：迭代器指向当前位置（初始在开头，即第一个字符之前）
    auto cursor = board.begin();
    
    int q;
    cin >> q;
    
    while (q--) {
        char op;
        cin >> op;
        
        if (op == '>') {  // 右移
            if (cursor != board.end()) {
                ++cursor;
            }
        }
        else if (op == '<') {  // 左移
            if (cursor != board.begin()) {
                --cursor;
            }
        }
        else if (op == 'I') {  // 刻写
            char c;
            cin >> c;
            // 在光标位置插入，插入后光标指向新元素的后继（即位置不变）
            board.insert(cursor, c);
        }
        else if (op == 'D') {  // 抹除
            if (cursor != board.begin()) {
                // 删除光标左侧的元素（即前一个元素）
                auto it = cursor;
                --it;
                board.erase(it);
            }
        }
    }
    
    // 输出结果
    for (char c : board) {
        cout << c;
    }
    cout << '\n';
    
    return 0;
}