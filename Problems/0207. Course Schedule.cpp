#define pb push_back
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int> {});    //adjacency list
        vector<int> in(numCourses,0);                           //list of in-degrees
        for(auto i:prerequisites){
            adj[i[0]].pb(i[1]);
            in[i[1]]++;
        }
        return kahn(numCourses, adj, in);
    }
    //=============== TOPOLOGICAL SORT ======================
    bool kahn(int n, vector<vector<int>>& adj, vector<int>& in){
        vector<int> res{};
        queue<int> q{};
        for(int i=0;i<n;i++)
            if(in[i]==0)
                q.push(i);
        while(!q.empty()){
            int cur = q.front();
            res.pb(cur);
            q.pop();
            for(int child:adj[cur]){ 
                in[child]--;
                if(in[child]==0)
                    q.push(child);
            }
        }
        return res.size() == n; 
    }
};
