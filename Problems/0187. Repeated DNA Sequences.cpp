class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> res{};
        
        for(int i=0; i+9<s.length(); i++){
            m[s.substr(i, 10)]++;
        }
        
        for(auto i:m){
            if(i.second > 1)
                res.push_back(i.first);
        }
        
        return res;
    }
};
