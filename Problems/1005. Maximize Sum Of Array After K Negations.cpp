class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res{};
        priority_queue<int, vector<int>, greater<int>> pq; //MIN HEAP
        for(auto i:nums)
            pq.push(i);
        
        while(k--){
            int temp = pq.top();
            if(temp == 0)
                break;
            pq.pop();
            pq.push(temp * -1);
        }
        
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
