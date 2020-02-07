class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return 1;
        int l{1},r{num/2},mid{};
        while(l<=r){
            mid = l + (r-l)/2;
            if((double)mid == (double)num/mid)
                return true;
            else if (mid > num/mid)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};
