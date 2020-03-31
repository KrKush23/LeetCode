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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int sum{0};
        helper(root,sum,0);
        return sum;
    }
    void helper(TreeNode* root, int &sum, bool check){
        if(!root->left and !root->right and check)
            sum+=root->val;
        if(root->left)  helper(root->left,sum,1);
        if(root->right) helper(root->right,sum,0);
    }
};
