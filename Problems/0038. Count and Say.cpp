#define pb push_back
class Solution {
public:
    string countAndSay(int n) {
        // BASE CASE
        if(n==1)
            return "1";
        // Recursion
        string s = countAndSay(n-1);
        
        string res{};
        int cnt{1};
        
        // we have to count...and return what we are saying
        for(int i=1;i<s.length();i++){
            // increase 'cnt' if same digit
            if(s[i]==s[i-1])
                cnt++;
            // else store this count with digit...and reset 'cnt' = 1
            else{
                res.pb(cnt+'0');
                res += s[i-1];
                cnt=1;
            }
        }
        // at last...store cnt and digit of last no.
        res.pb(cnt+'0');
        res += s[s.length()-1];
        return res;
    }
};
