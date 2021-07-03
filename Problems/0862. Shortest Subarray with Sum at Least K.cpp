class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n+1;
        vector<int> prefix(n+1, 0);     // can use 'nums' instead of new prefix vector
        deque<int> d;
        
        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
            if(prefix[i] >= k)        // checking for subarray 0 to i
                res = min(res, i);
            
            while(!d.empty() and prefix[i] - prefix[d.front()] >= k){
                res = min(res, i-d.front());
                d.pop_front();
            }
            
            while(!d.empty() and prefix[i] <= prefix[d.back()])
                d.pop_back();
                
            d.push_back(i);
        }
        return res <= n ? res : -1;
    }
    // 1st WHILE LOOP =================
    // TRYING to reduce the subarray if possible..
    // if d[0] to i >= k...then no need to check for d[0] to i+1...it doesn't go towards better solution
    // so remove d[0]
    
    // 2nd WHILE LOOP =================
    // if nums[i] is not +VE...prefix[i] <= prefix[d.back()]
    // we want to keep deque increasing...so remove until prefix[i] > prefix[d.back()]
};
