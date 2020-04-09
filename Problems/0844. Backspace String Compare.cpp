class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                s.erase(s.begin()+i);
                i--;
                if(i>=0){
                    s.erase(s.begin()+i);
                    i--;
                }
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                t.erase(t.begin()+i);
                i--;
                if(i>=0){
                    t.erase(t.begin()+i);
                    i--;
                }
            }
        }
        return s==t;
    }
};
