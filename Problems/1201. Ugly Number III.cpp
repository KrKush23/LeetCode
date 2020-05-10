class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int l{1}, r{INT_MAX}, mid{};
        while(l<r){
            int mid = l + (r-l)/2;
            int cur_cnt = mid/a + mid/b + mid/c - mid/lcm(a,b) - mid/lcm(b,c) - mid/lcm(a,c) + mid/(lcm(a,lcm(b,c)));
            if(cur_cnt < n)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    long lcm (long a, long b){
        return a*b/__gcd(a,b);
    }
};
