/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = NULL, *cur = head, *next = NULL;
        
        // REACHING start of the specified position
        while(--left){
            prev = cur;
            cur = cur->next;
            right--;
        }
        
        // FOR connecting this list to the reversed portion
        ListNode *connect = prev, *tail=cur;
        
        //REVERSING till specified position
        while(right--){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        if(connect != NULL)
            connect->next = prev;
        else
            head = prev;
        
        tail->next = cur;
        return head;
    }
};
