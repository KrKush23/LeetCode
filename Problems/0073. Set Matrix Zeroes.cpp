class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows{}, cols{};
        int n = matrix.size(), m = matrix[0].size();
        
        //getting indices of 0's
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
        
        // replacing each row
        for(auto r:rows)
            for(int j=0; j<m; j++)
                matrix[r][j] = 0;
        
        // replacing each col
        for(auto c:cols)
            for(int i=0; i<n; i++)
                matrix[i][c] = 0;
    }
};
