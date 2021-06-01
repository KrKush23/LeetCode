class Solution {
	int n, m;
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxArea{0};
		n = grid.size();
		m = grid[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1)
					maxArea = max(maxArea, dfs(grid, i, j));
			}
		}
		return maxArea;
	}

	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 or j<0 or i >= n or j >= m or grid[i][j] == 0)
			return 0;
		grid[i][j] = 0;
		int cnt{1};
		cnt += dfs(grid, i + 1, j);
		cnt += dfs(grid, i, j + 1);
		cnt += dfs(grid, i - 1, j);
		cnt += dfs(grid, i, j - 1);
		return cnt;
	}

};
