#define ii pair<int,int> 
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n*n;
        
        // BFS ==========================================
        queue<int> q;
        vector<bool> vis(target+1,0);
        q.push(1);
        vis[1] = 1;
        int moves{1}; //starting from 1
        
        while(!q.empty()){
            int size = q.size();
            for(int k=0; k<size; k++){
                int cur = q.front();
                cout<<cur<<"\n";
                q.pop();
                
                for(int i=1; i<=6; i++){
                    int next = cur+i;
                    int row = (next - 1)/n;     // counting from bottom
                    int col = (next - 1)%n;     // counting from front
                    int x = (n-1) - row;        // changing to count from top
                    int y = (row & 1) ? (n-1-col) : col; // odd row -> change to count from right
                    
                    if(board[x][y] > 0)
                        next = board[x][y];
                    if(next == target)
                        return moves;
                    if(!vis[next]){
                        q.push(next);
                        vis[next] = 1;
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
