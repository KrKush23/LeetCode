#define pb push_back
class Solution {
    vector<vector<int>> adj, bridges;
    vector<bool> vis;
    vector<int> in, low;
    int timer;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        vis.resize(n, 0);
        in.resize(n);
        low.resize(n);
        
        //building graph
        for(auto i:connections)
            adj[i[0]].pb(i[1]), adj[i[1]].pb(i[0]);
        
        //DFS
        timer = 0;
        dfs(0);   // since graph is CONNECTED...no need of FOR LOOP
        
        return bridges;
    }
    
    // DFS TO FIND BRIDGES in a GRAPH
    void dfs(int src, int parent = -1){
        vis[src] = 1;
        in[src] = low[src] = timer++;
        
        for(auto nbr: adj[src]){
            if(nbr == parent)
                continue;
            else if(vis[nbr])       //BACK EDGE
                low[src] = min(low[src], in[nbr]);
            else{                   //FRONT EDGE
                dfs(nbr, src);
                low[src] = min(low[src], low[nbr]);
                if(low[nbr] > in[src])      // BRIDGE condition
                    bridges.pb({src, nbr});
            }
        }
    }
};
