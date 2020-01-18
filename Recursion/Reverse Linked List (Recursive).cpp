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
    //refre gfg
    ListNode* reverseList(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL)
            return head;
        //recursive case
        ListNode *rest=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
};
