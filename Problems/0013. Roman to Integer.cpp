class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans{m[s[0]]};
        for(int i=1;i<s.length();i++){
            if(m[s[i-1]]<m[s[i]])
                ans+=m[s[i]]-2*m[s[i-1]];
            else
                ans+=m[s[i]];
        }
        return ans;
    }
};
