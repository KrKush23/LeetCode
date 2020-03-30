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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans{};
        if(!root)   return ans;
        string s{};
        s += to_string(root->val);      // adding root value ahead of dfs
        //BASE CASE:   Leaf Nodes
        if(!root->left and !root->right)    ans.pb(s); 
        //RECURSIVE CASES:  Non-Leaf Nodes
        if(root->left)      dfs(root->left, s, ans);
        if(root->right)     dfs(root->right, s, ans);
        return ans;
    }
    void dfs(TreeNode *root, string s, vector<string> &ans){
        s += "->" + to_string(root->val);       // adding node value before performing further dfs
        //BASE CASE:   Leaf Nodes
        if(!root->left and !root->right){
            ans.pb(s);
            return;
        }    
         //RECURSIVE CASES:  Non-Leaf Nodes
        if(root->left)  dfs(root->left, s, ans);
        if(root->right) dfs(root->right, s, ans);
}
};
