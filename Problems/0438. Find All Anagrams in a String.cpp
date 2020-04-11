class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l{0} ,r {0}, pending=p.length();
        vector<int> pmap(26,0),ans{};
        for(auto i:p)
            pmap[i-'a']++;          //counting all chars of 'p'
        while(r<s.length()){
            if(pmap[s[r++]-'a']-- >0)   //if present in 'p'
                pending--;
            if(pending ==0)             //f an anagram
                ans.push_back(l);
            if((r-l == p.length()) and pmap[s[l++]-'a']++ >= 0)         //if length of window = len(p) and char[left] is present in p
                pending++;
        }
        return ans;
    }
};
