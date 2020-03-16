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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans{};
        if(root == NULL)
            return ans;
        double avg{0};
        queue<TreeNode*> q{};
        q.push(root);
        int nc{};
        TreeNode *node{};
        while(!q.empty()){
            nc=q.size();
            long sum{0},temp{nc};
            while(nc--){
                node = q.front();
                q.pop();
                sum+= node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            avg= (double)sum/temp;
            ans.pb(avg);
        }
        return ans;
    }
};
