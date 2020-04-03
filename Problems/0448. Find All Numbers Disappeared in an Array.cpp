class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1,0),ans{};
        for(auto i:nums)
            v[i]++;
        for(int i=1;i<n+1;i++)
            if(v[i]==0)
                ans.push_back(i);
        return ans;
    }
};
