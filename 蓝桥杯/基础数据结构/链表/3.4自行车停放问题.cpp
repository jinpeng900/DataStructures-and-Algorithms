#include<iostream>

using namespace std;

const int N = 2000100;

struct node
{
    int preid;
    int data;
    int nextid;
}Nodes[N];

int locate[N];
int now;

void init()
{
    Nodes[0].nextid = 1;
    Nodes[1].preid = 0;
    now = 2;
}

void insert(int k , int x)
{
    Nodes[now].data = x;
    locate[x] = now;
    Nodes[now].nextid = Nodes[k].nextid;
    Nodes[now].preid = k;
    Nodes[Nodes[k].nextid].preid = now;
    Nodes[k].nextid = now;
    now++;
}


int main()
{
    int n , a;
    cin >> n >> a;
    init();
    insert(0 , a);
    n--;
    while (n)
    {
        int x , y , z;
        cin >> x >> y >> z;
        int temp = locate[y];
        if (z == 0)
        {
            insert(Nodes[temp].preid , x);
        }
        else
        {
            insert(temp , x);
        }
        n--;
    }
    for (int i = Nodes[0].nextid ; i != 1 ; i = Nodes[i].nextid)
    {
        cout << Nodes[i].data << " ";
    }
    return 0;
}