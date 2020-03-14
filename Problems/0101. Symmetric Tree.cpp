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
        return root == NULL || check(root->left,root->right);
    }
    bool check(TreeNode* leftRoot, TreeNode* rightRoot){
        //both are NULL
        if(leftRoot == NULL and rightRoot == NULL)  return true;
        //both have values
        else if(leftRoot !=NULL and rightRoot != NULL){
            //same values
            if(leftRoot->val == rightRoot->val)
                return check(leftRoot->left,rightRoot->right) and check(leftRoot->right,rightRoot->left);
            //otherwise
            return false;
        }
        //other cases
        return false;
    }
};
