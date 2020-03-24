class Solution {
public:
    string convertToTitle(int n) {
        string s{};
        while(n>0){
            n--;
            char ch = (n%26) +'A';
            s.push_back(ch);
            n/=26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
