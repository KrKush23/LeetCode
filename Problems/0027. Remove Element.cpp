class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())    return 0;
        int i=0,n=nums.size();
        for(int j=n-1;i<=j;i++){
            if(nums[i]==val)
                swap(nums[i--],nums[j--]);
        }
        return i;
    }
};
