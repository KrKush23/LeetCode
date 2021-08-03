class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // ============== USING 1D DP ARRAY AND 1 VAR ================
        int rows = matrix.size();
        int cols = (rows>0)? matrix[0].size():0;
        
        int maxSide{};
        int prev{}; // for TOP-LEFT
        vector<int> dp(cols+1,0);
        
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1'){
                    dp[j] = min({prev, dp[j-1], dp[j]}) + 1; // min of top-left, left, top
                    maxSide = max(maxSide, dp[j]);
                }else{
                    dp[j]=0;
                }
                prev = temp;
            }
        }
        return maxSide*maxSide; // area of the square
        
        // ============== USING 2D DP MATRIX ================
        
        // int rows = matrix.size();
        // int cols = (rows>0)? matrix[0].size(): 0;
        
        // int maxSide{0};
        // vector<vector<int>> dp(rows+1, vector<int> (cols+1,0));
        
        // for(int i=1;i<=rows;i++){
        //     for(int j=1;j<=cols;j++){
        //         if(matrix[i-1][j-1]=='1'){
                       // min of TOP, LEFT, TOP-LEFT
        //             dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        //             maxSide = max (maxSide, dp[i][j]);
        //         }
        //     }
        // }
        
        // return maxSide*maxSide; // area of the square
    }
};
