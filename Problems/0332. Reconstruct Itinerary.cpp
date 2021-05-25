#define pb push_back
class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		map<string, multiset<string>> graph{};
		for (auto i : tickets) {
			graph[i[0]].insert(i[1]);
		}
		vector<string> route{};
		dfs("JFK", route, graph);
		reverse(route.begin(), route.end());
		return route;
	}

	void dfs(string node, vector<string>& route, map<string, multiset<string>>& graph) {
		while (graph[node].size()) {
			auto cur = *(graph[node].begin());
			graph[node].erase(graph[node].begin());
			dfs(cur, route, graph);
		}
        // must push_back while returning to get correct ROUTE
		route.pb(node);
		return;
	}

};
