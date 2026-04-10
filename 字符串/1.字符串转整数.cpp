#include <iostream>
#include <string>
#include <climits> // 包含 INT_MAX 和 INT_MIN

using namespace std;

int myAtoi(string s) {
    int i = 0;
    int sign = 1;
    long long res = 0; // 使用 long long 防止中间过程溢出

    // 1. 跳过前导空格
    while (i < s.length() && s[i] == ' ') {
        i++;
    }

    // 2. 检查符号
    if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. 转换数字并处理溢出
    while (i < s.length() && isdigit(s[i])) {
        res = res * 10 + (s[i] - '0');

        // 检查是否超过 int 范围
        if (sign == 1 && res > INT_MAX) return INT_MAX;
        if (sign == -1 && -res < INT_MIN) return INT_MIN;
        
        i++;
    }

    return (int)(res * sign);
}

int main() {
    cout << myAtoi("   -42") << endl;    // 输出 -42
    cout << myAtoi("4193 with words") << endl; // 输出 4193
    return 0;
}