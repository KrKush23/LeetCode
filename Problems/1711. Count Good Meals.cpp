class Solution {
    int mod = 1e9 + 7;
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> counter{};
        // int res{0};
        long long res{0}; // do %mod at last..to save time
        
        for(auto x:deliciousness){
            for(int i=1; i<=(1<<22); i*=2){ // highest power of 2 possible -> 21 = 1<<22
                if(counter.count(i-x)){
                    res += counter[i-x];
                    // res %= mod;
                }   
            }
            counter[x]++;
        }
        return res%mod;
    }
};
