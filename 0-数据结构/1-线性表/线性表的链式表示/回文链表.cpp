# include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


bool isPalindrome(ListNode* head){
    stack<ListNode*> path;
    ListNode* p = head;
    while (p != nullptr){
        path.push(p);
        p = p->next;
    }

    ListNode* q = head;
    while (!path.empty()){
        ListNode* node = path.top();
        path.pop();
        if (node->val != q->val){
            return false;
        }
        q = q->next;
    }
    return true;

}