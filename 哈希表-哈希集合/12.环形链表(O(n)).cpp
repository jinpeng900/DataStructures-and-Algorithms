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
    unordered_map<ListNode* , int> path;
    
    ListNode* p = head;
    while (p != nullptr){
        path[p]++;
        if (path[p] > 1){
            return true;
        }
        p = p->next;
    }
    return false;
}
