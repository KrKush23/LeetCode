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
    // get successor (NOT INORDER NECESSARILY)
    TreeNode* getSuccesor(TreeNode *cur){
        cur = cur->right; //we know right EXISTS
        while(cur!=NULL and cur->left != NULL)
            cur = cur->left;
        return cur;
    }
    // delete node
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return root; //root is NULL
        
        if(key < root->val)         //reaching NODE
            root->left = deleteNode(root->left, key);
        else if(key > root->val)    //reaching NODE
            root->right = deleteNode(root->right, key);
        else{
            if(root->left == NULL){ // LEFT IS NULL or BOTH NULL
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }else if(root->right == NULL){ // RIGHT IS NULL
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }else{    // BOTH NOT NULL
                TreeNode *succ = getSuccesor(root);
                root->val = succ ->val;     
                root->right = deleteNode(root->right, succ->val); // delete succesor
            }   
        }
        return root;
    }
};
