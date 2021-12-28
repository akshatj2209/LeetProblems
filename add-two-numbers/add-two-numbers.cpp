/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode *l3 = new ListNode((l1->val + l2->val + c)%10);
        ListNode *p=l3;
        c = (l1->val + l2->val + c)/10;
        l1 =  l1->next;
        l2 = l2->next;
        
        while(l1!= nullptr && l2!=nullptr){
            l3->next = new ListNode();
            l3 =  l3->next;
            l3->val = (l1->val + l2->val + c)%10;
            c= (l1->val + l2->val + c)/10;
            l1 =  l1->next;
            l2 = l2->next;
            
        }
        while(l1!=nullptr){
            l3->next = new ListNode();
            l3 = l3->next;
            l3->val = (l1->val + c)%10;
            c= (l1->val + c)/10;
            l1 = l1->next;
        }
        while(l2!=nullptr){
            l3->next = new ListNode();
            l3 = l3->next;
            l3->val = (l2->val + c)%10;
            c= (l2->val + c)/10;
            l2 =  l2->next;
        }
        if(c!=0){
            l3->next = new ListNode();
            l3= l3->next;
            l3->val=c;
        }
        
        return p;
        
    }
};