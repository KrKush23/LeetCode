class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> counts{};
        int ans{0},sum{0},n=nums.size();
        counts[0]=-1;
        for(int i=0;i<n;i++){
            sum += (nums[i])? 1:-1;
            if(counts.find(sum)==counts.end())
                counts[sum]=i;  //if that 'sum' wasn't encountered before
            else
                ans = max(ans, i-counts[sum]); // if 'sum' was found before
        }
        return ans;
    }
};
