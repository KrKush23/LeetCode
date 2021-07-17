class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));
        int row = n, col = n;
        int r=0, c=0;
        int val = 1;
        
        while(r < row and c < col){
            // RIGHT
            for(int i=c; i<col; i++)
                matrix[r][i] = val++;
            r++;
            
            // DOWN
            for(int i=r; i<row; i++)
                matrix[i][col-1] = val++;
            col--;
            
            // LEFT
            if(r < row){
                for(int i=col-1; i>=c; i--)
                    matrix[row-1][i] = val++;
                row--;
            }
            
            // UP
            if(c < col){
                for(int i=row-1; i>=r; i--)
                    matrix[i][c] = val++;
                c++;
            }
        }
        return matrix;
    }
};
