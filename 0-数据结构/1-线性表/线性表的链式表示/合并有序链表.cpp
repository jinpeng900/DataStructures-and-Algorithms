# include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * p1 = list1;
        ListNode * p2 = list2;
        ListNode * r = new ListNode();
        ListNode *head = r;

        while (p1 != nullptr && p2 != nullptr){
            
            if (p1->val <= p2->val){
                r->next = p1;
                p1 = p1->next;
            }
            else{
                r->next = p2;
                p2 = p2->next;
            }
            r = r->next;
        }

        if (p1 == nullptr){
            r->next = p2;
        }

        if (p2 == nullptr){
            r->next = p1;
        }
        return head->next;
}