#define pb push_back
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v = nums;
        nums.clear();
        if(v.empty())
            return 0;
        nums.pb(v[0]);
        for(int i=1;i<(int)v.size();i++)
            if(v[i]!=v[i-1])
                nums.pb(v[i]);
        return nums.size();
    }
};
