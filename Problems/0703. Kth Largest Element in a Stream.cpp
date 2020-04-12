class KthLargest {
    priority_queue <int, vector<int>, greater<int>> pq{}; //to make the priority queue act as an MIN_HEAP
    int _k;             // to store value of 'k'
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k)         // we want to store only the k largest elements to get kth largest as top of min_heap
                pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size()<_k)            
            pq.push(val);
        else if(val > pq.top()){    //will push only if needed, as checking is faster than insertion
            pq.pop();
            pq.push(val);
        }
        return pq.top();            // top() is the root of min_heap here
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
