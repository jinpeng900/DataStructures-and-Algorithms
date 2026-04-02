#include<iostream>

using namespace std;

typedef struct node 
{
    int data;
    node * next;
}node;


node * Createnode(int i)
{
    node * head = new node();
    head->data = i;
    head->next = NULL;
    return head;
}


node * node_list(int n)
{
    node * head = Createnode(1);
    node * temp = head;
    for (int i = 2 ; i <= n ; i++)
    {
        node * new_node = new node();
        new_node->data = i;
        new_node->next = temp->next;
        temp->next = new_node;
        temp = new_node;
    }
    temp->next = head;
    return head;
}


int main()
{
    int n , m;
    cin >> n >> m;
    node * head = node_list(n);
    node * current = head;
    node * prev;
    int count = 0;
    while(n >= 1)
    {
        count++;
        if(n == 1)
        {
            cout << head->data << endl;
            break;
        }

        if(count == m)
        {
            if (current == head)
            {
                head = current->next;
            }
            cout << current->data << " ";
            prev->next = current->next;
            delete current;
            current = prev->next;
            count = 0;
            n--;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}

