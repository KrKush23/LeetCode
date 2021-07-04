class Solution {
    int n;
    vector<bool> vis;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vis.resize(n);
        
        int cc{0};
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, isConnected);
                cc++;
            }
        }
        return cc; // connected components
        
    }
    // DFS on adjcency MATRIX
    void dfs(int src, vector<vector<int>>& isConnected){
        vis[src] = 1;
        
        for(int nbr=0; nbr<n; nbr++){
            if(nbr!=src and isConnected[src][nbr] and !vis[nbr])
                dfs(nbr, isConnected);
        }
    }
};
