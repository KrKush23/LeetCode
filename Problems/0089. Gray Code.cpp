class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0}; // for n=0
        
        for(int i=0; i<n; i++){        // (n-1) times
            int sz = res.size();       // to get (the previous elements..b4 adding new ones)
            for(int j= sz-1; j>=0; j--){
                int temp = res[j] + (1 << i); // adding 1 at iTH position
                res.push_back(temp);
            }
        }
        return res;
        
    }
    /*
        n=0 -> 0
        n=1 -> 0, 1
        n=2 -> 00, 01, 11, 10
        n=3 -> copy n=2, add 1 to all in reverse
            -> 00, 01, 11, 10, 10, 11, 01, 00 , add 1 in reverse
            -> 00, 01, 11, 10, 110, 111, 101, 100 (done)
    */
};
