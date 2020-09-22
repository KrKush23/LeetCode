class Solution {
public:
    //============= BOYER - MOORE ALGORITHM ==============
    int majorityElement(vector<int>& nums) {
        int cnt{0}, ans{};
        for(auto i:nums){
            if(cnt==0)
                ans=i;
            cnt += (ans == i) ? 1 : -1;
        }
        return ans;
    }
};
