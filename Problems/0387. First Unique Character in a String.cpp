class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> rec(26,{0,0});
        int n = s.length();
        for(int i=0;i<n;i++){
            if(rec[s[i]-'a'].first==0)
                rec[s[i]-'a']={1,i};
            else if(rec[s[i]-'a'].first>0)
                rec[s[i]-'a'].first=-1;
        }
        int ans{INT_MAX};
        for(auto i:rec)
            if(i.first>0)
                ans = min(ans,i.second);
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
