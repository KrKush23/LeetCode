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
    ListNode* reverse(ListNode* head){
        ListNode *prev{NULL}, *cur{head}, *next{NULL};
        
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    void merge(ListNode* l1, ListNode* l2){
        while(l1){
            ListNode *next1{l1->next}, *next2{l2->next};
            l1->next = l2;
            
            if(!next1)
                break;
            
            l2->next = next1;
            
            l1 = next1;
            l2 = next2;            
        }
    }
public:
    void reorderList(ListNode* head) {
        if(!head or !head->next)
            return;
        
        ListNode *l1{head}, *l2{};
        ListNode *prev{nullptr}, *slow{head}, *fast{head};
        
        // 1. Separating list into two part from middle
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        // 2. Reverse 2nd half
        l2 = reverse(slow);
        
        // 3. Merge l1 and l2
        merge(l1, l2);
    }
};
