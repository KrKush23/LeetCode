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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans{};
        if(root == NULL)
            return ans;
        queue<TreeNode*> q{};
        q.push(root);
        stack<int> node_counts{}, node_vals{};
        int nc{0};
        TreeNode *node{};
        while(!q.empty()){
            nc=q.size();
            node_counts.push(nc);
            while(nc--){
                node = q.front();
                q.pop();
                node_vals.push(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        vector<int> temp{};
        while(!node_counts.empty()){
            nc = node_counts.top();
            node_counts.pop();
            while(nc--){
                temp.pb(node_vals.top());
                node_vals.pop();
            }
            reverse(temp.begin(),temp.end());
            ans.pb(temp);
            temp.clear();
        }
        return ans;
    }
};
