class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq{}; // {val, index}
        vector<int> res{};
        
        for(int i=0; i<nums.size(); i++){
            // check everytime if 1st element goes out of window
            if(!dq.empty() and dq.front().second <= (i-k))
                dq.pop_front();
            
            // ensure decreasing order before pushing current element
            while(!dq.empty() and dq.back().first < nums[i])
                dq.pop_back();
            dq.push_back({nums[i], i});
            
            // once window reaches its size..
            // start taking 1st element each time
            if(i>=(k-1))
                res.push_back(dq.front().first);
        }
        
        return res;
    }
};
