class Solution {
public:
    string removeDuplicateLetters(string s) { 
        vector<int> counter(26, 0), used(26, 0);
        for(auto ch:s)
            counter[ch - 'a']++; //get frequency
        
        string res{};
        for(auto ch:s){
            counter[ch-'a']--;      //decrease frequency
            if(used[ch-'a']++ > 0)   // if TAKEN move NEXT
                continue;
            while(!res.empty() and 
                  res.back() > ch and counter[res.back() - 'a'] > 0){
                used[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res.push_back(ch);
        }
        return res;
    }
};
