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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BASE CASES
        if(!root)   
            return NULL;
        if(root->val == p->val or root->val == q->val)
            return root;
        
        auto l = lowestCommonAncestor(root->left , p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        
        if(l!=NULL and r!= NULL) //nodes found both side -> this is LCA
            return root;
        if(!l and !r)            // NULL from both side
            return NULL;
        return (!l) ? r : l;     // FOUND 1 side
    }
};
