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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* newhead=head->next;
        ListNode* remaining=head->next->next;
        head->next->next=head;
        head->next=swapPairs(remaining);
        return newhead;
        
    }
};
