class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9 +1;    //SHORTCUT for below given way
    }
};
/*
    The digital root is the difference between the number and 
    the largest multiple of 9 less than the number itself.
            
            
        if(num==0)return 0;                   // Special case. 
        int digit_sum=num-9*((num-1)/9);      // Difference between number and largest 
                                              // multiple of 9 gives us digital root.
        return digit_sum;
*/
