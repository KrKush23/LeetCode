class Solution {
public:
    int tribonacci(int n) {
        if(n<2)
            return n;
        if(n == 2)
            return 1;
        
        int fib1{0}, fib2{1}, fib3{1};
        int res{0};
        
        for(int i=3; i<=n; i++){
            res = fib1 + fib2 + fib3;
            fib1 = fib2;
            fib2 = fib3;
            fib3 = res;
        }
        
        return res;
    }
};
