class Solution {
    bool isValid(int row, int col, int num, vector<vector<char>>& board){
        // check in row and column
        for(int i=0; i<9; i++){
            if( i != col and board[row][i] == ('0'+num))
                return 0;
            if( i != row and board[i][col] == ('0'+num))
                return 0;
        }
        // check in 3x3 square
        int i = row - (row%3);
        int j = col - (col%3);
        for(int k=0; k<3; k++){
            for(int l=0; l<3; l++){
                if( i+k != row and j+l != col and board[i+k][j+l] == ('0'+num))
                    return 0;
            }
        }
        return 1;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.' and !isValid(i, j, board[i][j]- '0', board))
                    return 0;
            }
        }
        return 1;
    }
};
