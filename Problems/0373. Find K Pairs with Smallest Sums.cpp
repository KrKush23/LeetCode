#define vi vector<int>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vi> res{};
        priority_queue<vi, vector<vi>, greater<vi>> pq;//MIN HEAP (val1 + val2, val1, val2, idx_of_val2)
        
        for(int i=0; i<n; i++)
            pq.push({nums1[i] + nums2[0], nums1[i], nums2[0], 0}); //combination of all of nums1 with num2[0]
        
        while(k-- and !pq.empty()){
            auto cur = pq.top();
            pq.pop();
            res.push_back({cur[1], cur[2]}); //get lowest sum pair
            
            if(cur[3] + 1 == m) //check if possible to get another pair with same element of nums1
                continue;
            pq.push({cur[1] + nums2[cur[3]+1], cur[1], nums2[cur[3]+1], cur[3]+1});//get next pair if possible            
        }
        return res;
    }
};
