#define pb push_back
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int> {});
        vector<int> in(numCourses,0);
        
        // create adjacency list and indegree VECTORS
        for(auto i:prerequisites){
            adj[i[1]].pb(i[0]);
            in[i[0]]++;
        }
        
        // topological sort
        return kahn(numCourses, adj, in);
    }
    
    bool kahn(int n, vector<vector<int>>& adj, vector<int>& in){
        vector<int> res{};
        queue<int> q{};
        
        for(int i=0;i<n;i++)
            if(in[i]==0) // take nodes with '0' INDEGREE
                q.push(i);
        
        while(!q.empty()){
            int cur = q.front();
            res.pb(cur);
            q.pop();
            
            for(int child:adj[cur]){ 
                in[child]--;       // reduce indegree of NEIGHBOURS
                if(in[child]==0)   // take it if INDEGREE becomes '0'
                    q.push(child);
            }
        }
        
        return res.size() == n; 
        // if less than 'n', means deadlock -> we can't finish all courses
    }
};
