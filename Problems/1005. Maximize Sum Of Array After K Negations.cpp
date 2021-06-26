class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // BETTER
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() and nums[i] < 0 and k > 0) {
            nums[i] = -nums[i];
            k--;
            i++;
        }
        if (k%2 == 0)
            return accumulate(nums.begin(), nums.end(), 0);
        int mn = *min_element(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0) - 2*mn;
        
        
        
        //MIN HEAP ==========================================
//         int res{};
//         priority_queue<int, vector<int>, greater<int>> pq; //MIN HEAP
//         for(auto i:nums)
//             pq.push(i);
        
//         while(k--){
//             int temp = pq.top();
//             if(temp == 0)
//                 break;
//             pq.pop();
//             pq.push(temp * -1);
//         }
        
//         while(!pq.empty()){
//             res += pq.top();
//             pq.pop();
//         }
//         return res;
    }
};
