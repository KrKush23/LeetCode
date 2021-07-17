class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res{};
        
        int row = matrix.size(), col = matrix[0].size();
        int r=0, c=0;
        
        while(r < row and c < col){
            // RIGHT
            for(int i=c; i<col; i++)
                res.push_back(matrix[r][i]);
            r++;
            
            // DOWN
            for(int i=r; i<row; i++)
                res.push_back(matrix[i][col-1]);
            col--;
            
            // LEFT
            if(r < row){
                for(int i=col-1; i>=c; i--)
                    res.push_back(matrix[row-1][i]);
                row--;
            }
            
            // UP
            if(c < col){
                for(int i=row-1; i>=r; i--)
                    res.push_back(matrix[i][c]);
                c++;
            }
        }
        return res;
    }
};
