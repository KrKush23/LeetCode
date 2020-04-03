class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
            return 0;
        while(n%3 == 0)
            n/=3;
        return n==1;
        //========== USING INT LIMITATIONS ==============
        /*
        // int limit = pow(3,floor(log10(INT_MAX)/ log10(3)));
           int limit = 1162261467; // = 3^19
           return n>0 and limit%n == 0;
        */
    }
};
