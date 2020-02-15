#define pb push_back
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s = countAndSay(n-1);
        string ans{};
        int cnt{1};
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])
                cnt++;
            else{
                ans.pb(cnt+'0');
                ans.pb(s[i-1]);
                cnt=1;
            }
        }
        ans.pb(cnt+'0');
        ans.pb(s[s.length()-1]);
        return ans;
    }
};
