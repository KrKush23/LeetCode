class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int table[26]={2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3}; 
        vector<string> valid{};
        for(auto s:words){
            int cur{table[toupper(s[0])-'A']};
            bool flag{1};
            for(auto c:s){
                if(cur != table[toupper(c)-'A']){
                    flag=0;
                    break;
                }
            }
            if(flag)
                valid.push_back(s);
        }
        return valid;
    }
};
