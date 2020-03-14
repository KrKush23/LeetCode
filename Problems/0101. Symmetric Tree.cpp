/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* leftRoot, TreeNode* rightRoot){
        //both are NULL
        if(leftRoot == NULL and rightRoot == NULL)  return true;
        //both have values
        else if(leftRoot !=NULL and rightRoot != NULL){
            //same values
            if(leftRoot->val == rightRoot->val)
                return isMirror(leftRoot->left,rightRoot->right) and isMirror(leftRoot->right,rightRoot->left);
            //otherwise
            return false;
        }
        //other cases
        return false;
    }
    //================SHORTER ISMIRROR FUNCTION============================
    
    // bool isMirror(TreeNode* leftRoot, TreeNode* rightRoot){
    //     //both are NULL
    //     if(leftRoot == NULL and rightRoot == NULL)  return true;
    //     //one is NULL
    //     if(leftRoot == NULL or rightRoot == NULL)  return false;
    //     //both have values
    //     return   (leftRoot->val == rightRoot->val) 
    //              and isMirror(leftRoot->left,rightRoot->right) 
    //              and isMirror(leftRoot->right,rightRoot->left);
    // }
};
