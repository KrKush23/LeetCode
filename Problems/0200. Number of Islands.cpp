class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt{};
        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    callbfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void callbfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j < 0  || i >= grid.size() || j >= grid[i].size() || grid[i][j]=='0')
            return ;
        grid[i][j]='0';
        callbfs(grid, i+1, j);  //down
        callbfs(grid, i, j+1);  //right
        callbfs(grid, i-1, j);  //up
        callbfs(grid, i, j-1);  //left
    }
};
