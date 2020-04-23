class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shifts{};
        while(m!=n){
            m>>=1;
            n>>=1;
            shifts++;
        }
        return n<<shifts;
    }
};
