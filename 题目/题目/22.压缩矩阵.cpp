#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n][n];
    int vis[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            vis[i][j] = 0;

    int sum = 1;
    int x = 0, y = 0;
    a[x][y] = sum;          /* 先把 1 写上 */
    vis[x][y] = 1;

    while (sum < n * n)
    {
        /* 向右：y+1 不越界且未访问 */
        while (y + 1 < n && !vis[x][y + 1])
        {
            y++;
            sum++;
            a[x][y] = sum;
            vis[x][y] = 1;
        }

        /* 向下：x+1 不越界且未访问 */
        while (x + 1 < n && !vis[x + 1][y])
        {
            x++;
            sum++;
            a[x][y] = sum;
            vis[x][y] = 1;
        }

        /* 向左：y-1 不越界且未访问 */
        while (y - 1 >= 0 && !vis[x][y - 1])
        {
            a[x][--y] = ++sum;
            vis[x][y] = 1;
        }

        /* 向上：x-1 不越界且未访问 */
        while (x - 1 >= 0 && !vis[x - 1][y])
        {
            a[--x][y] = ++sum;
            vis[x][y] = 1;
        }
    }

    /* 输出 */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d " , a[i][j]);
        }
        printf("\n");
    }
    return 0;
}