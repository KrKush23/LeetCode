class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector< int> ans(2,0);
         int mask{};
        for( int i:nums)
            mask^=i;
        mask = mask & (~(mask-1)); 
        // this bit is only set in one of the two numbers present only once int the array
        for( int i:nums){
            if((mask & i) == 0)
                ans[0]^= i; //xor with all nos. NOT having that bit set (INCLUDES 1st no.)
            else
                ans[1]^= i; //xor with all nos. HAVING that bit set (INCLUDES 2nd no.)
        }
        //since all other nos. are occuring twice only reqd nos are present
        return ans;
    }
};
