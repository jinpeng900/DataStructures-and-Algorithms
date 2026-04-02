#include<iostream>
#include<vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts)
{
    int len = accounts.size();
    vector<int>path;
    for (int i = 0 ; i < len ; i++)
    {
        int num = 0;
        for (int j = 0 ; j < accounts[i].size() ; j++)
        {
            num += accounts[i][j];
        }
        path.push_back(num);
    }
    int temp = path[0];
    for (int i = 0 ; i < len ; i++)
    {
        if (temp < path[i])
        {
            temp = path[i];
        }
    }
    return temp;
}

int main()
{
    vector<vector<int>> accounts = { {1 , 5} , {7 , 3} , {3 , 5} };
    cout << maximumWealth(accounts) << endl;
    return 0;
}