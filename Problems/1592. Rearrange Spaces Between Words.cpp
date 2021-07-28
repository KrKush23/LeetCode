class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        vector<string> words{};
        string word{}, res{};
        
        for(auto c:text){
            if(c == ' '){
                spaces++;
                if(!word.empty())
                    words.push_back(word);
                word = "";
            }else{
                word += c;
            }
        }
        if(!word.empty()) //checking if last char was not " "
            words.push_back(word);
        
        // only 1 word
        if(words.size() == 1)
            return words.back() + string(spaces, ' ');

        //more than 1 word
        int gap = spaces / (words.size() - 1);
        int suffix = spaces % (words.size() - 1);
        
        for(auto word:words)
            res += word + string(gap, ' ');
        res = res.substr(0, res.size() - gap); //remove last gap added
        res += string(suffix, ' ');            // add left spaces
        
        return res;
    }
};
