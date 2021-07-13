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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *connect = list1, *tail;
        b -= (a-1);
        
        while(--a)
            connect = connect->next;
        
        tail = connect->next;
        connect->next = list2;
        
        while(b){
            tail = tail->next;
            b--;
        }
        
        while(connect->next)
            connect = connect->next;
        
        connect->next = tail;        
        
        return list1;
    }
};
