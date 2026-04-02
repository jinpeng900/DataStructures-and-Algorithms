#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;


int calPoints(vector<string>ops)
{
    stack<int> path;
    for(int i = 0 ; i < ops.size(); i++)
    {
        string str = ops[i];
        if (str[0] == '-')
        {
            int num = stoi(str);
            path.push(num);
        }
        else if (str == "+")
        {
            int num1 = path.top();
            path.pop();
            int num2 = path.top();
            path.push(num1);
            path.push(num1 + num2);
        }
        else if(str == "D")
        {
            int num = path.top();
            path.push(num * 2);
        }
        else if (str == "C")
        {
            path.pop();
        }
        else
        {
            int num = stoi(str);
            path.push(num);
        }
    }
    int res = 0;
    while(path.empty() != true)
    {
        res += path.top();
        path.pop();
    }
    return res;
}


int main()
{
    vector<string> ops = {"5" , "-2" , "4" , "C" , "D" , "9" , "+" , "+"};
    int result = calPoints(ops);
    cout << result << endl;
    system("pause");
    return 0;
}