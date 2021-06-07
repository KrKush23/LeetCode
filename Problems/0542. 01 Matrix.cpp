class Solution {
    int n, m;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        if(n==0)    return mat;
        m=mat[0].size();
        
        vector<vector<int>> res (n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q{};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }
        
        vector<int> dx{-1, 0, 1, 0};
        vector<int> dy{0, -1, 0, 1};
        
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
                
            for(int k=0; k<4; k++){
                int i2 = i+dx[k], j2=j+dy[k];
                if(i2>=0 and j2>=0 and i2<n and j2<m){
                    if(res[i2][j2] > res[i][j] + 1){
                        res[i2][j2] = res[i][j] + 1;
                        q.push({i2, j2});
                    }
                }
            }
        }
        
        return res;
    }
};
