class Solution {
    int n, m;
    
    int aliveNeighbours(int r, int c, vector<vector<int>>& board){
        int cnt=0;
        for(int i:{r-1, r, r+1}){
            for(int j:{c-1, c, c+1}){
                if((i==r and j==c) or i<0 or j<0 or i>=n or j>=m)
                    continue;;
                if(board[i][j] == 1 or board[i][j] == 3) // a/c to state
                    cnt++;
            }
        }
        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();
        
         // Old | New | State
         //  0  |  0  |   0
         //  1  |  0  |   1
         //  0  |  1  |   2
         //  1  |  1  |   3
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int nbr = aliveNeighbours(i, j, board);

                if(board[i][j]){
                    if(nbr == 2 or nbr == 3)
                        board[i][j] = 3;
                }else{
                    if(nbr == 3)
                        board[i][j] = 2;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 1)
                    board[i][j] = 0;
                else if(board[i][j] == 3 or board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};
