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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0)  //EDGE cases
            return head; 
        
        int len{1};
        ListNode *cur = head;
        while(cur->next){       // get length of LIST
            len++;
            cur = cur->next;
        }
        
        cur->next = head;   // connect last to head
        k %= len; // NEW 'k'
        k = len - k; // no. of nodes after which nodes come at start
        
        while(k--)          // go til required node
            cur = cur->next;
        
        head = cur->next;   //make its next as head
        cur->next = NULL;   //update next ot NULL
        
        return head;
    }
};
