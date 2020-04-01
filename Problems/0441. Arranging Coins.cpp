class Solution {
public:
    int arrangeCoins(int n) {
        if(n<2)
            return n;
        long l{0},r{n },mid{},sum{};
        while(l<r){
            mid = l+(r-l)/2;
            sum = (mid*(mid+1))/2;
            if(sum <= n)
                l = mid+1;
            else 
                r=mid;
        }
        return l-1;
    }
};
