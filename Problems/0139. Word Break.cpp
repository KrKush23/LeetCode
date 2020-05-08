class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1,0);
        dp[0]=1;//word can be made up till here from dict
        set<string> words(wordDict.begin(), wordDict.end());
        
        for(int l=0; l<n; l++){
            if(!dp[l])      //means words starting from here should not be searched for
                continue;
            //finding all matching words from starting from l
            for(int h = l; h<=n; h++){ 
                string t = s.substr(l, h-l);
                if(words.find(t) != words.end())
                    dp[h]=1;
            }
        }
        return dp[n];
    }
};
