class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int res{};
        int n = nums.size();
        int i=0, j=n-1;
        
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum > k)
                j--;
            else if(sum < k)
                i++;
            else{
                res++;
                i++; j--;
            }
        }
        return res;
    }
};
