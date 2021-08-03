class Solution {
    int n, m;
    int memo[200][200];
    int res;
    
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    bool isValid(int i, int j, vector<vector<int>>& matrix){
        if(i<0 or j<0 or i>=n or j>=m)
            return 0;
        return 1;
    }
    
    int dfs(int r, int c, vector<vector<int>>& matrix){
        // LOOK UP
        if(memo[r][c] > 0)
            return memo[r][c];
        
        int res = 0;
        
        for(int i=0; i<4; i++){
            int R = r+dr[i];
            int C = c+dc[i];
            if(isValid(R, C, matrix) and matrix[R][C] > matrix[r][c]){ // stricly increasing
                int cur = dfs(R, C, matrix);
                res = max(res, cur);
            }
        }
        
        return memo[r][c] = res + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(memo, 0, sizeof(memo)); // intializing memo[][]
        
        int res=0;
        
        // DFS with MEMOIZATION ===================
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cur = dfs(i, j, matrix); // dfs
                res = max(res, cur);
            }
        }
        return res;
    }
};
