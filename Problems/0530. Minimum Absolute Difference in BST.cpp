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
    int minDiff = INT_MAX;
    int val = -1;
public:
    // INORDER TARVERSAL..sorted values
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return minDiff;
        
        getMinimumDifference(root->left);
        
        if(val >= 0)
            minDiff = min(minDiff, root->val - val);
        val = root->val;
        
        getMinimumDifference(root->right);
        
        return minDiff;
    }
};
