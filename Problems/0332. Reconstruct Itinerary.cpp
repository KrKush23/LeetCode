#define pb push_back
class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
        //multiset is used...so that..list gets SORTED
		map<string, multiset<string>> graph{};
        
		for (auto i : tickets)  //adj list
			graph[i[0]].insert(i[1]); //directed EDGES
        
		vector<string> route{};
		dfs("JFK", route, graph); //DFS =====
        
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
        // WE are using recursion as STACK...
        // so that we don't get stuck in a DEADEND...while preserving LEXICAL ORDER
		route.pb(node);
		return;
	}

};
