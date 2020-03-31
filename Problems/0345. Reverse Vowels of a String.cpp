class Solution {
public:
    string reverseVowels(string s) {
        int l{0}, r{(int)s.length()-1};
        while(l<r){
            while(!isVowel(s[l]) and l<r)
                l++;
            while(!isVowel(s[r]) and l<r)
                r--;
            if(l<r)
                swap(s[l++],s[r--]);
        }
        return s;
    }
    bool isVowel(char i){
        if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U')
            return 1;
        return 0;
    }
};
