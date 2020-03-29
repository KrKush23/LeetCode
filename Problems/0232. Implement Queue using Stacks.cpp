// NOTE : To understand, see Leetcode solution (Approach #2)


class MyQueue {
    stack<int> st1{},st2{};
    int front{};
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(st1.empty())
            front=x;
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int temp = st2.top();
        st2.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(!st2.empty())
            return st2.top();
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() and st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
