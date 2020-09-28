class Solution {
    map<string, string> m{
        {"2","abc"},
        {"3","def"},
        {"4","ghi"},
        {"5","jkl"},
        {"6","mno"},
        {"7","pqrs"},
        {"8","tuv"},
        {"9","wxyz"}
    };
    vector<string> res{};
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.empty())
            backtrack("", digits);
        return res;
    }
    
    void backtrack(string cur,string digits){
        // Base Case
        if(digits.empty()){
            res.push_back(cur);
            return;
        }
        
        string digit = digits.substr(0,1);
        //Trying each letter corresponding to the digit
        for(auto letter:m[digit]){
            //Recursion -> sending 1 less digit
            backtrack(cur + letter, digits.substr(1,digits.length()-1));
        }
    }
};
