class Solution {
public:
    int findComplement(int num) {
        int temp{num}, mask{};
        while(temp){
            temp>>=1;
            mask<<=1;
            mask |= 1;
        }
        return mask & (~num);
    }
};
