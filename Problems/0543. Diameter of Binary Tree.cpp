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
    int ans{};
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        height(root);
        return ans;
    }
    int height(TreeNode* root){
        if(!root)   return 0;
        int L = height(root->left);
        int R = height(root->right);
        ans = max(ans, L+R);
        return max(L,R) + 1;
    }
};
