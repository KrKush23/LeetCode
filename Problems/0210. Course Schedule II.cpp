#define pb push_back
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int> {});
		vector<int> in (numCourses, 0);
        
        // create adjacency list and indegree VECTORS
		for (auto i : prerequisites) {
			graph[i[1]].pb(i[0]);
			in[i[0]]++;
		}
        
        // topological sort
		return kahn(numCourses, graph, in);
	}

	vector<int> kahn(int n, vector<vector<int>>& graph, vector<int>& in) {
		vector<int> res{};
		queue<int> q{};
        
		for (int i = 0; i < n; i++)
			if (in[i] == 0) // take nodes with '0' INDEGREE
				q.push(i);
		
		while (!q.empty()) {
			int cur = q.front();
			res.pb(cur);
			q.pop();
            
			for (auto nbr : graph[cur]) {
				in[nbr]--;          // reduce indegree of NEIGHBOURS
				if (in[nbr] == 0)   // take it if INDEGREE becomes '0'
					q.push(nbr);
			}
		}
        
        // if less than 'n', means deadlock -> we can't finish all courses
		if (res.size() < n) 
			return {};
		return res;
	}
};
