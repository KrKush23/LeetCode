class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n); // 1D
        dp[0] = triangle[0][0];
        
        for(int k=1; k<n; k++){
            for(int i=k; i>=0; i--){
                if(i==0)
                    dp[i] = dp[i] + triangle[k][i];
                else if(i==k)
                    dp[i] = dp[i-1] + triangle[k][i];
                else
                    dp[i] = min(dp[i], dp[i-1]) + triangle[k][i];
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
