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
    int idx = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder,int parent_value = INT_MAX) {
        if(idx == preorder.size() or preorder[idx] > parent_value)
            return NULL;
        int cur_value = preorder[idx++];
        TreeNode *node = new TreeNode(cur_value);
        node->left = bstFromPreorder(preorder, cur_value);
        node->right = bstFromPreorder(preorder, parent_value);
        return node;
    }
};
