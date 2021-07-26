class Solution {
    string s1, s2, s3;
    int len1, len2, len3;
    unordered_map<string, bool> mem;
    
    bool helper(int i, int j, int k){
        // BASE CASE
        if(k == len3)
            return (i == len1 and j == len2) ? true : false;
        
        string key = to_string(i) + "*" + to_string(j) + "*" + to_string(k);
        // LOOK UP
        if(mem.find(key) != mem.end())
            return mem[key];
        
        // RECURSIVE
        if(i == len1)
            return mem[key] = (s2[j] == s3[k]) ? helper(i, j+1, k+1) : 0;
        
        if(j == len2)
            return mem[key] = (s1[i] == s3[k]) ? helper(i+1, j, k+1) : 0;
        
        bool one{0}, two{0};
        if(s1[i] == s3[k])
            one = helper(i+1, j, k+1);
        if(s2[j] == s3[k])
            two = helper(i, j+1, k+1);
        
        return mem[key] = one or two;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        
        if(len1 + len2 != len3)
            return false;
        
        
        // MEMOIZATION ===============
        // return helper(0, 0, 0);
        
        // BOTTOM-UP =================
        vector<vector<bool>> dp(len1+1, vector<bool> (len2+1));
        dp[0][0] = true;
        
        for(int j=1; j<=len2; j++)
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1];
        
        for(int i=1; i<=len1; i++)
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1];
        
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                dp[i][j] = (dp[i-1][j] and s1[i-1] == s3[i+j-1]) or
                           (dp[i][j-1] and s2[j-1] == s3[i+j-1]);
            }
        }
        
        return dp[len1][len2];
    }
};
