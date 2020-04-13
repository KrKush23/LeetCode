/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long minValue{LONG_MIN},maxValue{LONG_MAX};
        return isValidBST(root, minValue, maxValue);
        
    }
    bool isValidBST(TreeNode* root, long minValue, long maxValue){
        if(!root) return 1;
        if(root->val <= minValue or root->val >= maxValue)  return 0;
        return isValidBST(root->left, minValue, root->val) and isValidBST(root->right, root->val, maxValue);
    }
};
