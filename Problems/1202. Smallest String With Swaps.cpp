class Solution {
    vector<int> par;
    
    int find(int a){
        if(par[a] < 0)
                return a;
        return par[a] = find(par[a]); // path compression
    }
    
    void union_(int a, int b){ // 'union' -> RESERVED KEYWORD
        int i = find(a);
        int j = find(b);
        
        // UNION BY RANK
        if(i != j){ // if not in same set
            if(-par[i] < -par[j]) // make 'i' -> bigger set
                swap(i, j);
            par[i] += par[j];
            par[j] = i;
            
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        par.resize(s.size(), -1);
        
         // map to have all indices of same group, together
        vector<vector<int>> m(s.size());  
        
        // union
        for(auto p: pairs)
            union_(p[0], p[1]);
        
        // placing a grp of indices together
        for(int i=0; i<s.size(); i++)
            m[find(i)].push_back(i);
        
        // getting each grp of indices
        for(auto &grp: m){
            string res{};
            for(auto i:grp)
                res += s[i];
            sort(res.begin(), res.end()); //sorting the characters in the group
            
            for(int i=0; i<grp.size(); i++) // placing them accordingly
                s[grp[i]] = res[i];
        }
        
        return s;
    }
};
