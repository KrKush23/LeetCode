int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
class Solution {
    int cnt{}, res{};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x{}, y{};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0)
                    cnt++;
                else if (grid[i][j] == 1)
                    x = i, y = j;
            }
        }
        dfs(grid, x, y);
        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 2) {
            if (cnt == -1)
                res++;
            return;
        }

        grid[x][y] = -1; //To Avoid BACK TRAVERSAL
        cnt--;

        for (int i = 0; i < 4; i++) {
            if (isValid(grid, x + dx[i], y + dy[i])) {
                dfs(grid, x + dx[i], y + dy[i]);
            }
        }

        grid[x][y] = 0; // BACKTRACK
        cnt++;
    }

    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if (x<0 or y<0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] == -1)
            return 0;
        return 1;
    }

};
