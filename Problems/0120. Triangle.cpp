class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int m = triangle.size(), n = (m>0)?triangle[m-1].size():0;
        vector<vector<int>> dp(m, vector<int> (n,0));
        for(int i=0;i<n;i++)
            dp[m-1][i] = triangle[m-1][i];
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<i+1; j++){
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
