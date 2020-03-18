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
    int pathCount{0};
    //function to perform simple DFS checking for each node
    int pathSum(TreeNode* root, int sum) {  //ALL PATHS STARTING FROM ROOT
        if(root){
            helper(root, sum);
            pathSum(root->left, sum);       //ALL PATHS STARTING FROM ROOT->LEFT
            pathSum(root->right, sum);      //ALL PATHS STARTING FROM ROOT->RIGHT
        }
        return pathCount;
    }
    //checking pathsum at each node and its children
    void helper(TreeNode* root, int sum){
        if(root){
            if(sum==root->val)
                pathCount++;
            helper(root->left, sum-root->val);
            helper(root->right, sum-root->val);
        }
    }
};
