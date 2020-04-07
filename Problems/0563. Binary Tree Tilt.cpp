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
    int findTilt(TreeNode* root) {
        if(!root)   return 0;
        int sum{};
        sum += abs(helper(root->left, sum)-helper(root->right, sum));
        return sum;
    }
    int helper(TreeNode* root, int &sum){
        if(!root)   return 0;
        int l{},r{};
        l = helper(root->left,sum);
        r = helper(root->right,sum);
        sum += abs(l-r);
        return root->val + l + r;
    }
};
