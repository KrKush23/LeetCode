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
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return helper(root, arr, 0);
    }
    bool helper(TreeNode* root, vector<int> &a, int idx){
        if(!root or idx>=a.size())
            return 0;
        if(!root->left and !root->right)
            return ((root->val==a[idx]) and (idx == a.size()-1));
        if(root->val == a[idx])
            return helper(root->left, a, idx+1) or helper(root->right, a, idx+1);
        return 0;
    }
};
