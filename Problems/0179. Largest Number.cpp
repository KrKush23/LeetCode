class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res{};
        vector<string> s{};
        for(auto i:nums)
            s.push_back(to_string(i));
        
        sort(s.begin(), s.end(), [](string s1, string s2){return s1+s2>s2+s1;});
        
        for(auto t:s)
            res += t;
        
        while(res[0] == '0' and res.length() > 1)
            res.erase(0, 1);
        return res;
    }
};
