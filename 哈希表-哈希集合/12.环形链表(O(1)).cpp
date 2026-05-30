# include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



bool hasCycle(ListNode *head) {
    if (head == nullptr){
        return false;
    }

    ListNode * slow = head;
    ListNode * quick = head->next;
    while (slow != quick){
        if (quick == nullptr || quick->next == nullptr){
            return false;
        }
        slow = slow->next;
        quick = quick->next->next;
    }
    return true;
}
