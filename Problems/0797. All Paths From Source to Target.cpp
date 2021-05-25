#define pb push_back
class Solution {
	vector<vector<int>> res{};
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> path{};
		dfs(0, path, graph);
		return res;
	}
	void dfs(int node, vector<int> path, vector<vector<int>>& graph) {
		path.pb(node);
		if (node == graph.size() - 1) {
			res.pb(path);
			return;
		}
		for (auto nbr : graph[node]) {
			dfs(nbr, path, graph);
		}
		return;
	}
};
