class Solution {
public:
    int integerReplacement(long n) {
        if(n==1)
            return 0;
        return helper(n);
        
    }
    int helper(long n){
        if(n<=1)
            return 0;
        if(n==2)
            return 1;
        if(n%2==0)
            return helper(n/2) + 1;
        else
            return min(helper((n+1)/2), helper((n-1)/2)) + 2;
        return 1;
    }
};
