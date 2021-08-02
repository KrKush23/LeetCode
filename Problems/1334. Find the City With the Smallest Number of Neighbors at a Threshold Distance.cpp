class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        
        // INITIALISATION
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INT_MAX;
            }
        }
        
        // adjacency matrix
        for(auto e:edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        
        // FLOYD WARSHALL algo
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++){
                    if(dist[i][k] != INT_MAX and dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
        
        int res{0}, minReachable{INT_MAX};
        
        for(int i=0; i<n; i++){
            int cnt{};
            // cnt no. of cities within THRESHOLD
            for(int j=0; j<n; j++)
                if(dist[i][j] <= distanceThreshold)
                    cnt++;
            
            if(cnt <= minReachable){ // update if possible
                minReachable = cnt;
                res = i;
            }
        }
        return res;
    }
};
