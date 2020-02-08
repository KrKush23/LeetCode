class Solution {
public:
    string breakPalindrome(string p) {
        int l{(int)p.length()};
        if(l<=1)
            return "";
        for(int i=0; i <l/2; i++)
            if(p[i]!='a'){
                p[i]='a';
                return p;
            }
        p[l-1]='b';
        return p;
    }
};
