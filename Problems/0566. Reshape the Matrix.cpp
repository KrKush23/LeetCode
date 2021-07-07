class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        
        if(n*m != r*c)
            return mat;
        
        vector<vector<int>> res(r, vector<int> (c));
        int i=0, j=0, x=0, y=0;
        while(i<n and j<m and x<r and y<c){
            res[x][y++] = mat[i][j++];
            if(j == m)
                j = 0, i++; 
            if(y == c)
                y = 0, x++;
        }
        return res;
    }
};
