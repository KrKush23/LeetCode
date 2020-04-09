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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head|| k==0)    return head;
        ListNode *fast{head}, *slow{nullptr};
        int n{};
        while(fast){
            slow = fast;
            fast = fast->next;
            n++;
        }
        k%=n;
        if(k==0)    return head;
        slow->next =head;
        slow = nullptr;
        fast = head;
        for(int i=0;i<n-k;i++){
            slow=fast;
            fast=fast->next;
        }
        slow ->next =nullptr;
        return fast;
    }
};
