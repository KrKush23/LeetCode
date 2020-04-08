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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow{head}, *fast{head};
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next)
            slow=slow->next;
        return slow;
    }
};
