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
    vector<int> v;
public:
    TreeNode* balanceBST(TreeNode* root) {        
        // get inorder of the tree
        // ITERATIVE INORDER
        stack<TreeNode*> st;
        while(true){
            while(root){    //LEFT
                st.push(root);
                root = root->left;
            }
            if(st.empty())  break;
            
            root = st.top();    //NODE
            st.pop();
            v.push_back(root->val); //store it
            
            root = root->right; //RIGHT
        }
        
        //build new tree;
        return buildTree(0, v.size()- 1);
    }
    
    TreeNode* buildTree(int l, int r){
        if(l > r)
            return NULL;
        
        int mid = l + (r-l)/2;          //find mid
        TreeNode *node = new TreeNode(v[mid]);  //create new node
        
        node->left = buildTree(l, mid-1);   //go left (l to mid-1)
        node->right = buildTree(mid+1, r);  //go right (mid+1 to r)
        
        return node;
    }
};
