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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans{};
        if(root == NULL)
            return ans;
        queue<TreeNode*> q{};
        vector<int> temp{};
        int nc{0};
        // nc = node_count
        q.push(root);
        TreeNode *node{};
        while(!q.empty()){
            nc=q.size();
            // To get all nodes of same level in one loop
            while(nc--){
                node = q.front();
                q.pop();
                temp.pb(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.pb(temp);
            temp.clear();
        }
        return ans;
    }
};
