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
    int getDecimalValue(ListNode* head) {
        vector<int> v{};
        ListNode *temp{head};
        while(temp){
            v.push_back(temp->val);
            temp =temp->next;
        }
        int ans{0},n=v.size()-1;
        for(int i=0;i<v.size();i++){
            if(v[i])
                ans += pow(2,n);
            n--;
        }
        return ans;
    }
};
