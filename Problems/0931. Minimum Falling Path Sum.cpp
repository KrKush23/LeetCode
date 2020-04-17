#define F first
#define S second
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.empty())   return 0;
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp (m, vector<int> (n));
        for(int i=0;i<n;i++)
            dp[m-1][i]=A[m-1][i];
        for(int i=m-2; i>=0; i--){
            for(int j=0;j<n;j++){
                int t = A[i][j];
                int best = t + dp[i+1][j];
                if(j>0)     best = min(best, t + dp[i+1][j-1]);
                if(j<n-1)   best = min(best, t + dp[i+1][j+1]); 
                dp[i][j] =best;
            }
        }
        int ans{INT_MAX};
        for(auto i : dp[0])
            ans = min(ans, i);
        return ans;
    }
//     dp[i][j] represents  MIN_SUM to reach bottm from that point
//     therefore we start from bottom-most point
//     and then check above points
};
