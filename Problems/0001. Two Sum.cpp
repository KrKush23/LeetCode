class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans{};
        map<int,int> m{};
        int compliment{};
        for(int i=0;i<(int)nums.size();i++){
            compliment = target - nums[i];
            if(m.find(compliment)!=m.end())
                return {m[compliment],i};
            m[nums[i]]=i;
        }
        return{-1,-1};
    }
};
