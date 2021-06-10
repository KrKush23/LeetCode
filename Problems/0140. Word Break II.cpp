class Solution {
public:
    
    void helper(string t, string s, int idx, vector<string>& dict, vector<string>& res){
        int l = s.length();
        // BASE (idx reaches end of 's')
        if(idx == l){
            t.pop_back();   //remove " "
            res.push_back(t);
            return;
        }
        
        //RECURSIVE
        string temp;
        for(int i=idx; i<l; i++){
            temp += s[i];
            if(find(dict.begin(), dict.end(), temp) != dict.end())
                helper(t + temp + " ", s, i+1, dict, res);
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> res{};
        //current string, given string, index from where we must check, dictionary, resultant vector
        helper("", s, 0, dict, res);
        return res;
    }
};
