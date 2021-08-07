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
    map <int, map<int, multiset<int>> > m; // MULTISET for sorted multiple occurences
    
    void helper(TreeNode* root, int row = 0, int col = 0){
        if(!root)
            return;
        
        m[col][row].insert(root->val); // keep track col and row wise
        helper(root->left, row+1, col-1);
        helper(root->right,row+1, col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root);
        
        vector<vector<int>> res{};
        for(auto i:m){
            vector<int> temp{};
            for(auto j:i.second){
                for(auto k:j.second)
                    temp.push_back(k);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
