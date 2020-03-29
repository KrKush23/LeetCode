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
    bool isPalindrome(ListNode* head) {
        ListNode *slow {head}, *fast {head};
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reversed(slow);  // reverses the right half of given linked list
        fast = head;            // fast goes back to head
        while(slow){
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
    // For reversing the right half of the given linked list
    ListNode* reversed(ListNode* head){
        ListNode *prev {}, *next{};
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
