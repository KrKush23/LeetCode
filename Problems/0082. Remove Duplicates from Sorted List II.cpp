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
        //=========== ITERATIVE ===================
        
        if(!head or !head->next)    return head;
        ListNode *dummy = new ListNode{};
        dummy->next=head;
        auto prev = dummy;
        while(prev->next){
            auto node=prev->next;
            while(node->next and node->val == node->next->val)
                node=node->next;
            if(node != prev->next)          //changes have been made
                prev->next=node->next;
            else                            //changes have not been made
                prev=node;         // or prev = prev->next;
        }
        return dummy->next;
        
        // ================= RECURSIVE ==============
        
        // if(!head)   return nullptr;
        // if(head->next and head->val == head->next->val){
        //     while(head->next and head->val == head->next->val)
        //         head = head->next;
        //     return deleteDuplicates(head->next);
        // }
        // head->next = deleteDuplicates(head->next);
        // return head;
    }
};
