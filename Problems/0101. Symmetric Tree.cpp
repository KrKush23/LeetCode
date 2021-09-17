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
    bool isMirror(TreeNode* L, TreeNode* R){
        if(!L and !R) // BOTH NULL
            return true;
        if(!L or !R)  // 1 is NULL
            return false;
        if(L->val != R->val)    // UNEQUAL values
            return false;
        
        return isMirror(L->left, R->right) and isMirror(L->right, R->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return (!root) or isMirror(root->left, root->right);
    }
};
