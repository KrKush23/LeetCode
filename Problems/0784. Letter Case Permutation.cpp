class Solution {
    vector<string> res{};
    
    void backtrack(string cur, int i, string s){
        // BASE CASE
        if(i == s.length()){
            res.push_back(cur);
            return;
        }
        
        // IF NUMBER
        if(isdigit(s[i])){
            backtrack(cur + s[i], i+1, s);
        }
        // IF ALPHABET
        else{
            backtrack(cur + (char)toupper(s[i]), i+1, s);
            backtrack(cur + (char)tolower(s[i]), i+1, s);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        res.clear();
        
        backtrack("", 0, s);
        return res;
    }
};
