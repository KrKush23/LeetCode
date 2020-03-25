class Solution {
public:
    int trailingZeroes(int n) {
        int ans{0}, mod{5};
        while(n>0){
            ans += n/mod;
            n /= mod;
        }
        return ans;
    }
    //https://www.youtube.com/watch?v=3Hdmv_Ym8PI&feature=youtu.be
};
