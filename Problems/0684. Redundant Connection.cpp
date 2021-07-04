class Solution {
    vector<int> par;
    
    int find(int a){
        while(a != par[a])
            a = par[a];
        return a;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // UNION FIND ===========================
        vector<int> res{};
        par.resize(1001); // Parent Array initialisation
        for(int i=0; i<par.size(); i++)
            par[i] = i;
        
        for(auto e:edges){
            int u = find(e[0]);
            int v = find(e[1]);
            
            if(u==v) // if 2 nodes with same parent are found -> this edge in REDUNDANT
                res = e;
            else
                par[v] = u;
        }
        return res;        
    }
};
