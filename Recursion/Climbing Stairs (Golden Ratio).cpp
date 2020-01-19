class Solution {
public:
    //Basically it's fibonacci numbers
    int climbStairs(int n) {
        if(n<4)
            return n;
        double goldenRatio = (1+sqrt(5))/2;
        return (int)round(pow(goldenRatio,n+1)/sqrt(5));
    }
};
