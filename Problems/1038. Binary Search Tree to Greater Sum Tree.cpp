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
    int val{};
public:
    TreeNode* bstToGst(TreeNode* root) {
        // REVERSE INORDER
        if(root){
            bstToGst(root->right);
            
            root->val += val;
            val = root->val;
            
            bstToGst(root->left);
        }
        return root;
    }
};
