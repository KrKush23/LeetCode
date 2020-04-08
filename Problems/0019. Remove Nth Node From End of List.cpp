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
        ListNode *dummy = new ListNode{};
        dummy->next=head;
        ListNode *first{dummy}, *second{dummy};
        for(int i=0;i<n;i++)
            first=first->next;
        while(first->next){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;//when head will be removed
    }
};
