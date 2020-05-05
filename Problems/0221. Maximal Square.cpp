class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // ============== USING 1D DP ARRAY AND 1 VAR ================
        int rows = matrix.size(), cols = (rows>0)? matrix[0].size():0;
        int max_length{}, prev{};
        vector<int> dp(cols+1,0);
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1'){
                    dp[j] = min({prev, dp[j-1], dp[j]}) + 1;
                    max_length = max(max_length, dp[j]);
                }
                else
                    dp[j]=0;
                prev = temp;
            }
        }
        return max_length*max_length;
        
        // ============== USING 2D DP MATRIX ================
        
        // int rows = matrix.size(), cols = (rows>0)? matrix[0].size(): 0;
        // int max_length{0};
        // vector<vector<int>> dp(rows+1, vector<int> (cols+1,0));
        // for(int i=1;i<=rows;i++){
        //     for(int j=1;j<=cols;j++){
        //         if(matrix[i-1][j-1]=='1'){
        //             dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        //             max_length = max (max_length, dp[i][j]);
        //         }
        //     }
        // }
        // return max_length*max_length;
    }
};
