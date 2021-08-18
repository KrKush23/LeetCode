class Solution {
public:
    string reverseWords(string s) {
        istringstream is{s};
        string temp{};
        
        is>>s; // breaking into each word
        
        while(is>>temp){ //reading ech word from 'is' 1 by 1
            s = temp + " " + s;
        }
        return s;
    }
};
