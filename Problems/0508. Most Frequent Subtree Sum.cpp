/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxFreq{};
    map<int, int> freq;
    
    int helper(TreeNode* root){
        if(!root)
            return 0;
        
        int sum{root->val};
        sum += helper(root->left);
        sum += helper(root->right);
        
        maxFreq = max(maxFreq, ++freq[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        
        vector<int> res{};
        for(auto i:freq){
            if(i.second == maxFreq)
                res.push_back(i.first);
        }
        
        return res;
    }
};
