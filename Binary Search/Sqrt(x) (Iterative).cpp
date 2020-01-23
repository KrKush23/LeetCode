class Solution {
public:
    int mySqrt(int x) {
        // Newton's Formula
        long r{x}; // To store 'r*r', as it will go out of limits of INT
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};
