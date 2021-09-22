class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n));
        dp[0][0] = mat[0][0];
        
        // PREFIX SUM ================================
        for(int i=1; i<n; i++)
            dp[0][i] = dp[0][i-1] + mat[0][i];
        for(int i=1; i<m; i++)
            dp[i][0] = dp[i-1][0] + mat[i][0];
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j];
            }
        }
        
        // RESULTANT MATRIX
        vector<vector<int>> res(m, vector<int> (n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res[i][j] = dp[min(i+k, m-1)][min(j+k, n-1)];
                
                if(j-k-1 >= 0)
                     res[i][j] -= dp[min(i+k, m-1)][j-k-1];
                
                if(i-k-1 >= 0)
                    res[i][j] -= dp[i-k-1][min(j+k, n-1)];
                
                if(i-k-1 >= 0 and j-k-1 >= 0)
                    res[i][j] += dp[i-k-1][j-k-1];
            }
        }
        
        return res;
    }
};
