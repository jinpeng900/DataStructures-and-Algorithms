#include<iostream>

using namespace std;

int a[201][201];

int vis[201][201] = {0};


int main()
{
    int m , n;
    cin >> m >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
    }
    int x = 1 , y = 1;
    int sum = 1;
    cout << a[1][1] ;
    vis[1][1] = 1;
    while (sum < m*n)
    {
        while (x+1 <= n && vis[x+1][y] == 0)
        {
            x++;
            cout << " " << a[x][y];
            vis[x][y] = 1;
            sum++;
        }
        while (y+1 <= m && vis[x][y+1] == 0)
        {
            y++;
            cout << " " << a[x][y];
            vis[x][y] = 1;
            sum++;
        }
        while (x-1 >= 1 && vis[x-1][y] == 0)
        {
            x--;
            cout << " " << a[x][y];
            vis[x][y] = 1;
            sum++;
        }
        while (y-1 >= 1 && vis[x][y-1] == 0)
        {
            y--;
            cout << " " << a[x][y];
            vis[x][y] = 1;
            sum++;
        }
        
        
        
        
    }
    return 0;
    
}