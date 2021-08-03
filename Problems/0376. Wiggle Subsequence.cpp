class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return n;
        
        // GREEDY algo =================================
        int prevDiff = nums[1] - nums[0];
        int cnt = (prevDiff != 0) ? 2 : 1;
        
        for(int i=2; i<n; i++){
            int diff = nums[i] - nums[i-1];
            
            if((diff>0 and prevDiff <= 0) or (diff<0 and prevDiff >= 0)){
                cnt++;
                prevDiff = diff;
            }
        }
        
        return cnt;
        
        // DP =========================
        int up[n], down[n];
        up[0] = down[0] = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                up[i]   = down[i-1] + 1;
                down[i] = down[i-1];
            }else if(nums[i] < nums[i-1]){
                down[i] = up[i-1] + 1;
                up[i]   = up[i-1];
            }else{
                up[i]   = up[i-1];
                down[i] = down[i-1];
            }
        }
        
        return max(up[n-1], down[n-1]);
    }
};
