class Solution {
public:
    bool isPowerOfFour(int n) {
        
        return (n>0) and (n&(n-1))==0 and ((n & 0x55555555) == n);
        
        //========== WITHOUT LOOPS ===========
            // if(n<1)
            //     return 0;
            // if((n & (n-1)) != 0)        //checks if is no. not a power of 2
            //     return 0;
            // return (n & 0x55555555) == n;   //checks if no. is a power of 4
        
            //  For Hex number 0x55555555, the binary representation is 0101 0101 0101,
            //  i.e., the bit 1 must be in the even position. In other words, if the bit 1
            //  (and the only bit 1) is in the even position, the result of  (num & 0x55555555)
            //  must be equal to 'n'. 
        
        //========== NAIVE APPROACH ==========
        /*if(n<1)
            return 0;
        while(n%4==0)
            n/=4;
        return n==1;
        */
    }
};
