#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}




int main()
{
    // construct a simple list: 1 -> 2 -> nullptr
    ListNode *head = new ListNode(1);
    ListNode *b = new ListNode(2);
    head->next = b;
    b->next = nullptr;

    ListNode *p = reverseList(head);
    ListNode *h = p;
    while(h != nullptr)
    {
        cout << h->val << endl;
        h = h->next;
    }

    // free memory
    ListNode *tmp = p;
    while (tmp != nullptr) {
        ListNode *n = tmp->next;
        delete tmp;
        tmp = n;
    }

    return 0;
}