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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //CREATE dummy
        ListNode *dummy = new ListNode{};
        dummy->next=head;
        
        ListNode *fast{dummy}, *slow{dummy};
        // FAST goes ahead 'n' nodes
        while(n--)
            fast=fast->next;
        
        // now FAST and SLOW...move 1 step at a time..till FAST is LAST node
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        // THEN delete the next of SLOW..and move its pointer accordingly
        ListNode *node = slow->next;
        slow->next = slow->next->next;
        delete node;
        
        return dummy->next;
    }
};
