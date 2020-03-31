class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rec(26,0);
        for(auto i:magazine)
            rec[i-'a']--;
        for(auto i:ransomNote)
            if(++rec[i-'a'] > 0)
                return 0;
        return 1;
    }
};
