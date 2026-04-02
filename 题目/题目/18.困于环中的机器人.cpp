#include<iostream>
using namespace std;

typedef struct node
{
    int x;
    int y;
    node * pur;
    node * next;
}node;


node * new_ls()
{
    node * head = new node();
    head->x = 0;
    head->y = 1;
    head->next = NULL;
    head->pur = NULL;
    node * temp = head;
    node * new_node;

    new_node = new node();
    new_node->x = 1;
    new_node->y = 0;
    new_node->pur = temp;
    temp->next = new_node;
    temp = new_node;

    new_node = new node();
    new_node->x = 0;
    new_node->y = -1;
    new_node->pur = temp;
    temp->next = new_node;
    temp = new_node;

    new_node = new node();
    new_node->x = -1;
    new_node->y = 0;
    new_node->pur = temp;
    temp->next = new_node;
    temp = new_node;
    temp->next = head;
    head->pur = temp;
    return head;
}


bool isRobotBounded(string instructions)
{
    int x = 0;
    int y = 0;
    node * head = new_ls();
    node * curr = head;
    for (int i = 0 ; i < 4 ; i++)
    {
        for (char instruction : instructions)
        {
            if (instruction == 'G')
            {
                x += curr->x;
                y += curr->y;
            }
            else if (instruction == 'L')
            {
                curr = curr->pur;
            }
            else
            {
                curr = curr->next;
            }
        }
        if (x == 0 && y == 0)
        {
            return true;
            break;
        }
    }
    return false;
}


int main()
{
    string str = "GGLLGG";
    bool flag = isRobotBounded(str);
    cout << flag << endl;
    return 0;  
}