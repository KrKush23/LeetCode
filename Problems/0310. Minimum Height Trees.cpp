#define pb push_back
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n <= 0)	return {};
		if (n == 1)	return {0};

		vector<vector<int>> graph(n, vector<int> {});
		vector<int> degree(n);
		vector<int> res{};

		for (auto i : edges) {
			graph[i[0]].pb(i[1]);
			graph[i[1]].pb(i[0]);
			degree[i[0]]++;
			degree[i[1]]++;
		}

		queue<int> q{};
		for (int i = 0; i < n; i++) {
			// leaf nodes
			if (degree[i] == 1)
				q.push(i);
		}
		// most centered nodes can't be more than 2
		while (n > 2) {
			int l = q.size();
			n -= l;
			for (int i = 0; i < l; i++) {
				int cur = q.front();
				q.pop();
				for (auto nbr : graph[cur]) {
					degree[nbr]--;
					if (degree[nbr] == 1)
						q.push(nbr);
				}
			}
		}
		// we wanted most centered nodes
		while (!q.empty()) {
			res.pb(q.front());
			q.pop();
		}
		return res;
	}
};
