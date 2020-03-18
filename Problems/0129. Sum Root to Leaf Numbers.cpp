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
    // int total{0};
    int sumNumbers(TreeNode* root) {
        int ans {0};
        helper(root, ans, 0);
        return ans;
    }
    void helper(TreeNode* root, int &ans, int csum){
        if(root){
            csum*=10;
            csum+=root->val;
            if(!root->left and !root->right)
                ans+=csum;
            else{
                helper(root->left, ans, csum);
                helper(root->right, ans, csum);
            }
        }
    }
};
