class Solution {
	vector<bool> visited{}, color{};
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		visited.resize(n);
		color.resize(n);

		for (int i = 0; i < n; i++) {
			if (!visited[i])
				if (!dfs(i, 0, graph))
					return 0;
		}
		return 1;
	}
	bool dfs(int src, int clr, vector<vector<int>>& graph) {
		visited[src] = 1;
		color[src] = clr;
		for (auto nbr : graph[src]) {
			if (!visited[nbr]) {
				if (!dfs(nbr, clr ^ 1, graph))
					return 0;
			}
			else {
				if (color[nbr] == color[src])
					return 0;
			}
		}
		return 1;
	}
};
