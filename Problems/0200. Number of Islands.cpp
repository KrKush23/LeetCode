class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt{};
        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j < 0  || i >= grid.size() || j >= grid[i].size() || grid[i][j]=='0')
            return ;
        grid[i][j]='0';
        dfs(grid, i+1, j);  //down
        dfs(grid, i, j+1);  //right
        dfs(grid, i-1, j);  //up
        dfs(grid, i, j-1);  //left
    }
};
