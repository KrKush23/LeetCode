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

#define iN pair<int, ListNode*>
struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }    
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy = ListNode(0);
        ListNode *cur = &dummy;
        // priority_queue<iN, vector<iN>, greater<iN>> pq; // MIN HEAP
        // or
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for(auto node: lists)
            if(node)
                pq.push(node);
        
        
        while(!pq.empty()){
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            
            if(cur->next)
                pq.push(cur->next);
        }
        
        return dummy.next;
    }
};
