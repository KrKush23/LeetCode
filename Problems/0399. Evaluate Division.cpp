#define pb push_back
class Solution {
    unordered_map<string, vector<pair<string, double>>> graph{};
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //Building a directed graph
        for(int i=0; i<equations.size(); i++){
            graph[equations[i][0]].pb({equations[i][1], values[i]});
            graph[equations[i][1]].pb({equations[i][0], 1.0/values[i]});
        }
        
        //Solution
        vector<double> res{};
        for(auto i:queries){
            string src{i[0]}, dest{i[1]};
            
            unordered_set<string> visited{};
            double ans{-1};
            
            if(graph.count(src))
                dfs(src, dest, visited, ans, 1.0);
            
            res.pb(ans);
        }
        return res;
    }
    
    void dfs(string src, string dest, unordered_set<string>& visited, double& ans, double temp){
        if(visited.count(src))  return;
        
        visited.insert(src);
        if(src == dest){
            ans = temp;
            return;
        }
        
        for(auto nbr:graph[src]){
            //Multiplying the values of each step towards the destination
            dfs(nbr.first, dest, visited, ans, temp*nbr.second);
        }
        
    }
};
