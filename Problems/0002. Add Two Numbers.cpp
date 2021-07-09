/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur=dummyHead;
        int carry{0};
        while(l1 != NULL || l2 != NULL){
            int sum = carry;
            sum += (l1!=NULL) ? l1->val : 0;
            sum += (l2!=NULL) ? l2->val : 0;
            
            carry = sum/10;
            cur->next = new ListNode(sum%10); //create new node
            cur = cur->next;
            
            if(l1!=NULL)    l1=l1->next;
            if(l2!=NULL)    l2=l2->next;
        }
        //AT last
        if(carry>0)
            cur->next = new ListNode(carry);
        
        return dummyHead->next;
    }
};
