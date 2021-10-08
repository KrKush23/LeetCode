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
    ListNode* reverse(ListNode* head, int k){        
        ListNode *cur = head, *prev = NULL, *next = NULL;
        
        while(k--){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        
        ListNode *cur{head}, *prev{&dummy};
        ListNode *tail = NULL;
        
        while(cur){
            tail = cur;
            int i = 0;
            
            while(cur and i < k){
                cur = cur->next;
                i++;
            }
            
            if(i < k){              // less than K nodes
                prev->next = tail;
            }else{                  // K nodes found to reverse
                prev->next = reverse(tail, k);
                prev = tail;
            }
        }
        
        return dummy.next;
    }
};
