/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans{};
        vector<int> temp{};
        if(!root)                           
            return ans;
        helper(ans, temp, root, sum);
        return ans;
    }
    void helper(vector<vector<int>> &ans, vector<int> &temp, TreeNode* root, int sum){
        if(!root)
            return;
        temp.pb(root->val);
        if(!root->left and !root->right and sum==root->val){
            ans.pb(temp);
            return;
        }
        helper(ans, temp, root->left, sum-root->val);
        if(root->left)  temp.pop_back();                //******IMPORTANT*******
        helper(ans, temp, root->right, sum-root->val);
        if(root->right) temp.pop_back();                //******IMPORTANT*******
    }
};
