/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* head){
        ListNode *cur=head, *prev=NULL, *next=NULL;
        while(cur!= NULL){ // 4 STEPS in the loop
            next = cur->next;
            cur->next = prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //IF nos. are not in reverse
//         l1 = reverseList(l1);
//         l2 = reverseList(l2);
        
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur=dummyHead;
        int carry{0};
        while(l1 != NULL || l2 != NULL){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum/10;
            cur->next = new ListNode(sum%10); //create new node
            cur = cur->next;
        }
        //AT last
        if(carry>0)
            cur->next = new ListNode(carry);
        
        return dummyHead->next;
        //IF you need to return no. in reverse
//         return reverseList(dummy->next);
    }
};
