class Solution {
public:
    int getSum(int a, int b) {
        // RECURSION ==================================
        return b == 0 ? a : getSum(a^b, (unsigned int) (a&b)<<1);
        
        // ITERATIVE ================================== 
        int carry{};
        while(b){
            carry = (unsigned int) (a & b) <<1;
            a = a ^ b;
            b = carry;
        }
        
        return a;
    }
};
