class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //=========== WITHOUT USING EXTRA SPACE ==========
        
        int n = nums.size();
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1; i<n;i++)
            ans[i] = ans[i-1]*nums[i-1];
        int temp=1;
        for(int i=n-2; i>=0; i--){
            temp *= nums[i+1];
            ans[i] *= temp;
        }
        return ans;
        
        //=========== USING EXTRA SPACE ===============
        
        // int n = nums.size();
        // vector<int> left(n), right(n), ans(n);
        // left[0] = right[n-1] = 1;
        // for(int i=1;i<n;i++)
        //     left[i] = left[i-1] * nums[i-1];
        // for(int i=n-2; i>=0; i--)
        //     right[i] = right[i+1] * nums[i+1];
        // for(int i=0;i<n;i++)
        //     ans[i] = left[i] * right[i];
        // return ans;
    }
};
