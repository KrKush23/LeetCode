/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur = head;
        
        // STEP 1 : create copy of each NODE after itself
        while(cur){
            Node *temp = cur->next;         //store current NEXT
            cur->next = new Node(cur->val); //create copy of current node
            cur->next->next = temp;         //connect copy to the list
            cur = cur->next->next;          //move to NEXT original node
        }
        
        // STEP 2 : COPY random ptrs...accordingly
        cur = head;
        while(cur){
            if(cur->random)
                cur->next->random = cur->random->next;  // copy random pointer to CORRECT nodes
            cur = cur->next->next;
        }
        
        Node *dummy = new Node(0);
        dummy->next = head;
        cur = dummy;
        
        // STEP 3 : SEPARATE the lists
        while(cur->next){
            Node *temp = cur->next;
            cur->next = temp->next;
            cur = cur->next;
            temp->next = cur->next;
            
        }
        return dummy->next;
    }
};
