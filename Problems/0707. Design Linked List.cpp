class Node{
public:
    int _val;
    Node* next;
    
    // Constructor
    Node(int val): _val{val}, next{nullptr} {} 
};

class MyLinkedList {
    Node* head;
    int size;
public:
    // Contructor
    MyLinkedList(): head{nullptr}, size{0} {}
    
    int get(int index) {
        if(index < 0 or index >= size)
            return -1;
        
        Node* cur{head};
        while(index--)
            cur = cur->next;
        
        return cur->_val;
                
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0  or index > size)
            return;
        
        Node* newNode = new Node(val);
        
        if(index == 0){
            newNode->next = head;
            head = newNode;
        }else{
            Node* cur{head};
            while(--index)
                cur = cur->next;
            
            newNode->next = cur->next;
            cur->next = newNode;
        }
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 or index >= size)
            return;
        
        Node* cur{head};
        if(index == 0){
            head = head->next;
            delete cur;
        }else{
            while(--index)
                cur = cur->next;
            
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        
        size--;
    }
    
    ~MyLinkedList(){
        Node* cur{head};
        while(head){
            head = head->next;
            delete cur;
            cur = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
