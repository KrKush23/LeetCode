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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> curLevel{}, nextLevel{};
        bool leftToRight{1};
        vector<int> cur{};
        vector<vector<int>> res{};

        if(!root)   return res; // BASE CASE

        curLevel.push(root); //push root

        while(!curLevel.empty()){ //if more nodes present
            while(!curLevel.empty()){  //while current level NOT TRAVERSED
                TreeNode *temp = curLevel.top();
                curLevel.pop();
                cur.push_back(temp->val);
                
                if(leftToRight){
                    if(temp->left)  nextLevel.push(temp->left);
                    if(temp->right) nextLevel.push(temp->right);
                }else{
                    if(temp->right) nextLevel.push(temp->right);
                    if(temp->left)  nextLevel.push(temp->left);
                }
            }
            
            leftToRight = !leftToRight; //switch direction
            swap(curLevel, nextLevel);  //swap levels
            
            res.push_back(cur);
            cur.clear();
        }
        return res;
    }
};
