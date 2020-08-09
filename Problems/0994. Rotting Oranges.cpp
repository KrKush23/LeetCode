class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt{}, n = grid.size(), m = grid[0].size(), res{};
        // cnt -> no. of fresh oranges
        // res -> time passed
        queue<pair<int,int>> q{};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){    // if ROTTEN
                    q.push({i,j});
                }else if(grid[i][j] == 1){  /// if FRESH
                    cnt++;
                }
            }
        }
        // Rotting Starts Now
        while(!q.empty()){
            int s=q.size();
            if(cnt == 0)  return res; //no more fresh oranges left
            while(s--){
                auto tmp = q.front();
                q.pop();
                int i=tmp.first, j=tmp.second;
                if(i>0 and grid[i-1][j]==1){   //above
                    cnt--;
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(j>0 and grid[i][j-1]==1){   //left
                    cnt--;
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(i<n-1 and grid[i+1][j]==1){   //bottom
                    cnt--;
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j<m-1 and grid[i][j+1]==1){   //right
                    cnt--;
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
            res++;
        }
        return (cnt==0)? res:-1;        
    }
};
