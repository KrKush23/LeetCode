class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans{};
        // ==== faster ==========
        for(auto i:nums){
            int d = floor(log10(i))+1;
            if(d%2==0)
                ans++;
        }
        return ans;
        
        //=========== slower =======
         
        // for(auto i:nums){
        //     int d{};
        //     while(i){
        //         d++;
        //         i/=10;
        //     }
        //     if(!(d&1))
        //         ans++;
        // }
        // return ans;
        
    }
};
