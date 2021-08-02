class Solution {
    vector<vector<int>> adj;
    vector<vector<bool>> par;
    
    void dfs(int src, vector<bool>& vis){
        vis[src] = 1;
        for(auto nbr:adj[src])
            if(!vis[nbr])
                dfs(nbr, vis);
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res{};
        
        // METHOD 2: CONNECTING a node with all the nodes reachable from it
        adj.assign(n, {});
        par.assign(n, {});
        
        for(auto p: prerequisites) //adjacency list
            adj[p[0]].push_back(p[1]);
        
        for(int i=0; i<n; i++){
            vector<bool> vis(n);
            dfs(i, vis); // dfs from each node, and mark REACHABLE nodes
            par[i] = vis;
        }
        
        //queries
        for(auto q:queries)
            res.push_back(par[q[0]][q[1]]);
        
        
        // METHOD 1: FLOYD-WARSHALL ALGO (modified to just true or false) ======================
        // Time: O(n^3) and Space: O(n^2)
        /*
        vector<vector<bool>> connected(n, vector<bool> (n, 0));
        
        // creating ADJACENCY MATRIX
        for(auto p:prerequisites)
            connected[p[0]][p[1]] = true;
        
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    connected[i][j] = connected[i][j] or (connected[i][k] and connected[k][j]);
        
        //QUERIES
        for(auto p: queries)
            res.push_back(connected[p[0]][p[1]]);
        */
        
        
        return res;
    }
};
