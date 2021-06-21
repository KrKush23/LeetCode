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
    int preIdx;         // current idx in preorder
    map<int,int> inIdx; // value -> idx in inorder
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIdx = 0; 
        for(int i=0; i<inorder.size(); i++) //create hashmap
            inIdx[inorder[i]] = i;
        
        return helper(preorder, 0, preorder.size()-1); //call helper
    }
    
    TreeNode* helper(vector<int>& preorder, int l, int r){
        //BASE CASE
        if(l > r)   return NULL;
        
        int nodeVal = preorder[preIdx++];       //get next preorder val..increase idx
        TreeNode *node = new TreeNode(nodeVal); // create node with value
        
        //in inorder...left of nodeVal..is left subtree
        //in inorder...right of nodeVal..is tight subtree
        node->left = helper(preorder, l, inIdx[nodeVal] - 1);  // call left firts..as values are decide by preIdx
        node->right= helper(preorder, inIdx[nodeVal] + 1, r); 
        
        return node;
    }
};
