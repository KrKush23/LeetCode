class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans{0};
        //========= BIT MANIPULATION TRICK ========
        while(n){
            ans++;
            n &= (n-1);
        }
        //============ NORMAL METHOD ==============
        /*
        while(n!=0){
            if(n&1)     
                ans++;
            n = n>>1;
        }
        */
        return ans;
    }
};
