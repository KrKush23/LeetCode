class Solution {
public:
    string sortString(string s) {
        vector<int> count(26);
        for(auto i:s)
            count[i - 'a']++;
        
        string res{};
        while(res.length() != s.length()){
            for(int i=0; i<26; i++){
                if(count[i]){
                    res+= char(i+'a');
                    count[i]--;
                }
            }
            
            for(int i=25; i>=0; i--){
                if(count[i]){
                    res+= char(i+'a');
                    count[i]--;
                }
            }
        }
        
        return res;
    }
};
