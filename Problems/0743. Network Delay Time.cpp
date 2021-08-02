#define ii pair<int, int>
#define F first
#define S second
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adj list
        vector<vector<ii>> adj(n+1, vector<ii>{});
        for(auto i:times)
            adj[i[0]].push_back({i[1], i[2]});
        
        // MIN HEAP
        priority_queue<ii, vector<ii>, greater<ii>> pq; //{wt, node} 
        vector<int> dist(n+1, -1);
        
        pq.push({0, k});
        dist[k] = 0;
        
        // DIJKSTRA algo (shortest single source path)
        while(!pq.empty()){
            int u = pq.top().S;
            pq.pop();
            
            for(auto [v, wt]: adj[u]){
                if(dist[v] == -1 or dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int res{};
        for(int i=1; i<=n; i++){
            if(dist[i] == -1) // if some node can't be visited
                return -1;
            res = max(res, dist[i]);
        }
        
        return res;
    }
};
