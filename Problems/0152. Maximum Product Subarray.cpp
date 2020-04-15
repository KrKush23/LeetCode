class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int final_max, cur_max, cur_min;
        final_max = cur_max = cur_min = nums[0];
        for(int i=1; i<n; i++){
            int temp = cur_max, t = nums[i];
            cur_max = max({cur_max*t, cur_min*t, t});
            cur_min = min({temp*t, cur_min*t, t});        //cz -ve * -ve can give a large +ve
            final_max = max(final_max, cur_max);
        }
        return final_max;
    }
};
