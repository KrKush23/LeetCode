#define F first
#define S second
class Solution {
public:
    string reorganizeString(string s) {
        if(!s.size())   return "";
        
        // frequency
        vector<int> count(26);
        for(auto i:s)
            count[i-'a']++;
        
        // max heap
        priority_queue<pair<int, char>> pq{};
        for(int i=0; i<26;i++){
            if(count[i]>0)
            pq.push({count[i], (char)('a'+i)});
        }
        
        string res{};
        while(pq.size() > 1){
            // taking top 2 chars
            auto [x, y] = pq.top();
            pq.pop();
            auto [m, n] = pq.top();
            pq.pop();
            
            res += y;
            res += n;
            // adding them back if more of them are left
            if(x>1) pq.push({x-1, y});
            if(m>1) pq.push({m-1, n});
        }
        
        // for last char
        if(!pq.empty()){
            auto [x, y] = pq.top();
            if(x>1) return ""; // cant place a char beside itself
            res += y;
        }
       
        return res;
        
    }
};
