class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long maxx{0}, sum{0};
        for(long long  i:nums){
            maxx = max(maxx, i);
            sum += i;
        }
        // largest sum of subarrays range from l to r
	    //  l -> largest no.
	    //  r -> sum of all nos.
       long long l{maxx}, r{sum}, mid{};
        while(l<r){
            mid = l + (r-l)/2;
            int pieces = split(nums, mid);
            // check for no. of partitions
            if(pieces > m)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    
    int split(vector<int> &nums,long long largestSum){
        int pieces {1};
        long long tmpSum{0};
        for(long long i:nums){
            if(tmpSum + i > largestSum){
                tmpSum = i;
                pieces++;
            }else{
                tmpSum += i;
            }
        }
        return pieces;
    }
};
