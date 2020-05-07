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
    bool isCousins(TreeNode* root, int x, int y) {
        int dx{-1}, dy{-1}, px{0}, py{0};
        parentAndDepth(root, x, 0, dx, px);
        parentAndDepth(root, y, 0, dy, py);
        return((dx == dy) and (px != py));
    }
    //there can't be any cousins at depth 1
    void parentAndDepth(TreeNode* root, int x, int d, int& dx, int& px){
        if(!root)
            return;
        if(root->left and root->left->val == x){
            dx = d + 1;
            px = root->val;
        }
        if(root->right and root->right->val == x){
            dx = d + 1;
            px = root->val;
        }
        if(dx != -1)
            return;
        parentAndDepth(root->left, x, d+1, dx, px);
        parentAndDepth(root->right, x, d+1, dx, px);
    }
};
