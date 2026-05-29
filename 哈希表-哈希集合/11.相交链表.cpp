# include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if (headA == nullptr || headB == nullptr){
        return nullptr;
    }

    ListNode* pA = headA;
    ListNode* pB = headB;

    unordered_set<ListNode*> path;
    
    while (pA != nullptr){
        path.insert(pA);
        pA = pA->next;
    }

    while (pB != nullptr){
        if (path.count(pB)){
            return pB;
        }
        else{
            pB = pB->next;
        }
    }
    return  nullptr;
    

}