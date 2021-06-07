#define pb push_back
class Solution {
    vector<int> vis;
public:
    void dfs(int src, vector<vector<int>>& adj){
        vis[src] = 1;
        for(auto nbr:adj[src]){
            if(!vis[nbr])
                dfs(nbr, adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n, vector<int> {});
        vis.resize(n, 0);
        int edges{}, cc{};
        
        for(auto i:connections){
            adj[i[0]].pb(i[1]), adj[i[1]].pb(i[0]);
            edges++;
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                cc++, dfs(i, adj);
        }
        
        //with only 1 cc -> edges - (n-1) redundant..
        // but if cc>1 means
        // we also add (c-1) ..to count some more REDUNDANT edges
        int redundant = edges - (n-1) + (cc-1);
        
        if(redundant >= cc - 1)
            return cc-1;
        return -1;
    }
};
