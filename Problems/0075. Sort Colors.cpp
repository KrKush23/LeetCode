class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return;
        int start{0}, end = nums.size()-1, i=0;
        while(i<=end and start <=end){
            if(nums[i]==0)
                swap(nums[i++], nums[start++]);
            else if(nums[i]==2)
                swap(nums[i], nums[end--]);
            else
                i++;
        }
    }
};
