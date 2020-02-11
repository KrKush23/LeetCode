class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        int furthestReachSoFar {0};
        for(int i=0; i<n; i++){
            if( i>furthestReachSoFar || furthestReachSoFar >= n-1)
                break;
            furthestReachSoFar = max(furthestReachSoFar, i+nums[i]);
        }
        return furthestReachSoFar >= n-1;
    }
};
