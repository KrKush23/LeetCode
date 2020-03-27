class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1{},m2{};
        // unordered_map is faster than map....
        // if ordering isn't important
        int n=s.length();
        for(int i=0;i<n;i++){
            if(m1.find(s[i])==m1.end() and m2.find(t[i])==m2.end()){
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if(m1.find(s[i])!=m1.end() and m2.find(t[i])!=m2.end()){
                if(m1[s[i]] != t[i] or m2[t[i]] != s[i])
                    return 0;
            }
            else
                return 0;
        }
        return true;
    }
};
