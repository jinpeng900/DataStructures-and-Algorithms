# include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode * p = head;
    int len = 0;
    while (p != nullptr){
        len++;
        p = p->next;
    }
    

    if (n == len){
        return head->next;
    }
    
    
    ListNode * cur_node = head;
    for (int i = 2 ; i < len - n+1; i++){
        cur_node = cur_node->next;
    }

    ListNode * move_node = cur_node->next;
    cur_node->next = move_node->next;
    
    
    return head;
}


int main(){
    ListNode * p1 = new ListNode(1);
    ListNode * p2 = new ListNode(2);
    ListNode * p3 = new ListNode(3);
    ListNode * p4 = new ListNode(4);
    ListNode * p5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    ListNode * ans = removeNthFromEnd(p1 , 4);
    ListNode * cur = ans;
    
    while (cur != nullptr){
        cout << cur->val << endl;
        cur = cur->next;
    }

    return 0;
    

}