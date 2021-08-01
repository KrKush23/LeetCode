class Solution {
    int n;
    
    int paint(int i, int j, vector<vector<int>>& grid, int clr){
        if(i<0 or j<0 or i>=n or j>=n or grid[i][j] != 1) // invalid or '0' or already colored
            return 0;
        
        grid[i][j] = clr;
        // dfs
        return 1 + paint(i+1, j, grid, clr) + paint(i, j+1, grid, clr) 
                 + paint(i-1, j, grid, clr) + paint(i, j-1, grid, clr);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> islands{0, 0}; 
        // 0-> 0 and islandId's will start from 2;
        // we can also use islandSize.size() as islandId for next island
    
        // COLOURING ISLANDS
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    islands.push_back(paint(i, j, grid, islands.size()));
                }
            }
        }
        
        int res = 0;
        
        // TRYING TO CONVERT EACH '0' to '1'
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    set<int> s;
                    
                    if(i+1 < n) s.insert(grid[i+1][j]);
                    if(j+1 < n) s.insert(grid[i][j+1]);
                    if(i-1 >-1) s.insert(grid[i-1][j]);
                    if(j-1 >-1) s.insert(grid[i][j-1]);
                    
                    int total = 1; //taking this land
                    
                    for(auto i:s)
                        total += islands[i];
                    
                    res = max(res, total);
                }
            }
        }
        
        // res == 0 -> whole grid is of 1's
        return (res == 0) ? n*n : res;
    }
};
