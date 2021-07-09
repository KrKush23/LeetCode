/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode *prev {}, *next{};
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        
        // FIND MIDDLE
        ListNode *slow {head}, *fast {head};
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse right half
        slow->next = reverse(slow->next);
        slow = slow->next;  // move slow to head of right half
        fast = head;        // move fast to head
        
        //check for PALINDROME
        while(slow){
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
