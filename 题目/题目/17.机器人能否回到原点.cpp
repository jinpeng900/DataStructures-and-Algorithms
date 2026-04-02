#include<iostream>
#include<string>
#include<stack>

using namespace std;

typedef struct node
{
    int x;
    int y;
}Node;

bool judgeCircle(string moves)
{
    Node * node = new Node();
    node->x = 0;
    node->y = 0;
    for (unsigned int i = 0 ; i < moves.size() ; i++)
    {
        if (moves[i] == 'L')
        {
            node->x += -1;
        }
        else if (moves[i] == 'R')
        {
            node->x += 1;
        }
        else if (moves[i] == 'U')
        {
            node->y += 1;
        }
        else
        {
            node->y += -1;
        }
    }
    if (node->x == 0 && node->y == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}




