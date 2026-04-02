#include<iostream>
#include<stack>

using namespace std;

class Solution
{
    public:
        bool isValid(string s)
        {
            int len = s.size();
            stack<char>str;
            for (int i = 0 ; i < len ; i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    str.push(s[i]);
                }
                if (str.empty() == true)
                {
                    return false;
                }
                else
                {
                    
                    char p = str.top();
                    if (s[i] == ')')
                    {
                        if (p == '(')
                        {
                            str.pop();
                        }
                        else
                        {
                            return false;
                        }

                    }
                    else if (s[i] == ']')
                    {
                        if (p == '[')
                        {
                            str.pop();
                        }
                        else
                        {
                            return false;
                        }

                    }
                    else
                    {
                        if (p == '{')
                        {
                            str.pop();
                        }
                        else
                        {
                            return false;
                        }

                    }
                }
            }
            if (str.empty() == true)
            {
                return true;
            }
            return false;
        }
};



int main()
{
    Solution s;
    if (s.isValid("]{") == true)
    {
        cout << "true" << endl;
    }  
    else
    {
        cout << "false" << endl; 
    }
    system("pause");
    return 0;
}