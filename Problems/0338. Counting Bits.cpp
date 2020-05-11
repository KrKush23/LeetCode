class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for(int i=1;i<=num;i++){
            if(i%2==0)
                ans[i] = ans[i/2];
            else
                ans[i] = ans[i-1] + 1;
        }
        
        //========== using function ==========
        
        // for(int i=1;i<=num;i++)
        //     ans[i] = __builtin_popcount(i);
        
        return ans;
    }
};
