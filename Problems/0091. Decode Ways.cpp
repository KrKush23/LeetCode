class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        int len = s.length();
        vector<int> dp(len+1);
        dp[len]=1;
        dp[len-1] = (s[len-1]=='0')? 0:1;
        for(int i = len-2; i>=0; i--){
            if(s[i]=='0')
                continue;
            if(stoi(s.substr(i,2))<=26)
               dp[i] = dp[i+1] + dp[i+2];
            else
               dp[i] = dp[i+1];
        }
        return dp[0];
    }
};
