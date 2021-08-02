class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // BELLMAN - FORD algo ==============================
        vector<int> cost(n, 1e8);
        cost[src] = 0;
        
        for(int i=0; i<=k; i++){ // k+1 times only; k stops -> k+1 edges
            vector<int> temp (cost);
            for(auto i: flights)
                temp[i[1]] = min(temp[i[1]], cost[i[0]] + i[2]);
            
            cost = temp;
        }
        return cost[dst] == 1e8 ? -1 : cost[dst];
    }
};

// NOTE: 1.dijkstra' algo -> TLE
