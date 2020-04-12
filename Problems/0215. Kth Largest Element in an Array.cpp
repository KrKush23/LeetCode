class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //============ USING MIN HEAP =============
        
        priority_queue <int, vector<int>, greater<int>> pq{};       // using priority queue as min_heap
        for(auto i:nums){
            if(pq.size()<k)
                pq.push(i);
            else if(i>pq.top()){
                pq.pop();
                pq.push(i);
            }
        }
        return pq.top();
    }
};
