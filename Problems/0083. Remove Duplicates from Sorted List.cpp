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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        ListNode *prev{head},*cur{head->next};
        while(prev != NULL and cur != NULL){
            if(prev->val == cur->val){
                prev->next = cur->next;
                cur->next = NULL;
                cur=prev->next;
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};
