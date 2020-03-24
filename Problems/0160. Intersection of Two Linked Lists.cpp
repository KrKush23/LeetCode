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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB)
            return NULL;
        ListNode *tempA {headA}, *tempB {headB};
        int countA{0},countB{0};
        while(tempA){
            countA++;
            tempA = tempA->next;
        }
        while(tempB){
            countB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        while(countA > countB){
            countA--;
            tempA = tempA->next;
        }
        while(countB > countA){
            countB--;
            tempB = tempB->next;
        }
        while(tempA){
            if(tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};
