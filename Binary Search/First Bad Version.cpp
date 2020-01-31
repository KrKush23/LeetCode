// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l{0},r{n},mid{};
        while(l<r){
            mid= l +(r-l)/2;
            if(!isBadVersion(mid))
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};
