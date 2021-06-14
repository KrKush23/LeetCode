class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int res{0};
        
        // VECTOR =======
        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        // ARRAY ========
        // faster.......too much
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // ONLY IF char matches UPDATE values
                // ELSE reset to '0'..here already '0' so skip
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                // UPDATE 'res' each time if possible
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};
