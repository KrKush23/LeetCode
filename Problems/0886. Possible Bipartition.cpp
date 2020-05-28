#define pb push_back
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj (n+1);
        for(int i=0; i<dislikes.size(); i++){   //Making adjacency list
            adj[dislikes[i][0]].pb(dislikes[i][1]);
            adj[dislikes[i][1]].pb(dislikes[i][0]);
        }
        // 2 colors -> 0 and 1
        vector<int> color(n+1, -1); //'-1' -> unvisited node
        for(int i=1; i<=n; i++){  //will check for all nodes to make sure multi-component graphs are solved too
            if(color[i] == -1){
                if(!isBipartite(adj, color, n, i))  //'i' is root of the search
                    return 0;
            }
        }
        return 1;
    }
    
    //BFS - helper================================
    bool isBipartite(vector<vector<int>>& adj, vector<int>& color, int n, int node){
        queue<int> q{};
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto neighbour: adj[cur]){
                if(color[neighbour] == color[cur]) //same color shows odd-cycle
                    return 0;
                if(color[neighbour] == -1){ //Unvisited node
                    color[neighbour] = 1 - color[cur];
                    q.push(neighbour);
                }
            }
        }
        return 1;
    }
};
