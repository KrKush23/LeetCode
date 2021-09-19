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
    long total{};
    long res{};
    long mod = 1e9+7;
    
    void getTotal(TreeNode* root){
        if(!root)
            return;
        
        total += root->val;
        getTotal(root->left);
        getTotal(root->right);
    }
    
    long subTreeSum(TreeNode* root){
        if(!root)
            return 0;
        
        long sum{};
        sum += subTreeSum(root->left);
        sum += subTreeSum(root->right);
        sum += root->val;
        
        res = max(res, (total - sum) * sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        getTotal(root);
        
        subTreeSum(root);
        
        return res%mod;
    }
};
