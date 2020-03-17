/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *head_global;  //so that HEAD can be controlled without taking 'call stack' in mind
    TreeNode* sortedListToBST(ListNode* head) {
        int size = findSize(head);
        head_global=head;
        cout<<size;
        return helper(0, size-1);
    }
    int findSize(ListNode* head){
        ListNode *temp = head;
        int c{0};
        while(temp != NULL){
            temp = temp->next;
            c++;
        }
        return c;
    }
    TreeNode* helper(int l, int r){
        if(l>r)
            return NULL;
        int mid = l + (r-l)/2;
        TreeNode *Left = helper(l, mid-1);
        TreeNode *node = new TreeNode(head_global->val);
        node->left = Left;
        head_global = head_global->next;
        node->right = helper(mid+1, r);
        return node;
    }
};
