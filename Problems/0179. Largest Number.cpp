class Solution {
public:
    string largestNumber(vector<int>& nums) {        
        sort(nums.begin(), nums.end(), [](int& a, int& b){
            string s1{""}, s2{""};
            s1 += to_string(a);
            s2 += to_string(b);
            
            return s1+s2 > s2+s1;
        });
        
        string res{""};
        for(auto i:nums)
            res += to_string(i);
        
        if(res.length() > 0 and res[0]=='0')  return "0";
        return res;
    }
};
