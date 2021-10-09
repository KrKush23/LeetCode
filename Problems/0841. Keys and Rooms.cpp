class Solution {
    int n;
    vector<bool> vis;
    
    void dfs(int src, vector<vector<int>>& rooms){
        vis[src] = 1;
        
        for(auto nbr: rooms[src]){
            if(!vis[nbr])
                dfs(nbr, rooms);
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis.resize(n);
        dfs(0, rooms);
        
        for(auto i:vis)
            if(!i)
                return false;
        return true;
    }
};
