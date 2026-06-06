# include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) , next(NULL) {}
};


ListNode* detectCycle(ListNode *head){
    unordered_map<ListNode* , int> path;
    ListNode * p = head;
    while (p != nullptr){
        path[p]++;
        if (path[p] >= 2){
            return p;
        }
        p = p->next;
    }
    return NULL;
}