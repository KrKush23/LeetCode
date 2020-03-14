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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int l = minDepth(root->left), r = minDepth(root->right);
        if(l==0 and r==0)   return 1;
        if(l==0)    return 1+r;
        if(r==0)    return 1+l;
        return min(l,r)+1;
    }
};
