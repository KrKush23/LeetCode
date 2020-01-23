class Solution {
public:
    int mySqrt(int x) {
        if (x<2)
            return x;
        int l{1},r{x},mid{};
        while(l<=r){
            int mid=l +(r-l)/2;
            if(mid> x/mid)
                r=mid-1;
            else{
                if((mid+1) > x/(mid+1))
                    // To get out of the loop
                    return mid;
                l=mid+1;
            }
        }
        // This statement is just to satisfy return type
        // Answer will be returned from else condition
        return mid;
    }
};
