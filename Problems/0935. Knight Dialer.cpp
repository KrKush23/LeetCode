class Solution {
    const int mod = 1e9+7;
    // 0 -> 4,6
    // 1 -> 6,8
    // 2 -> 7,9
    // 3 -> 4,8
    // 4 -> 3,9,0
    // 5 -> no where
    // 6 -> 1,7,0
    // 7 -> 2,6
    // 8 -> 1,3
    // 9 -> 2,4
    // digits from which a digit CAN BE REACHED
    // eg -> 0 can be reached from 4,8....not cz 0 can reach 4,8...it just that moves here are both ways
    vector<vector<int>> moves = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
    
        
public:
    int knightDialer(int n) {
        
        vector<int> dp1(10, 1), dp2(10);
        while(--n){ // --n -> cz (n-1) times 
            for(int i=0; i<10; i++){
                int temp{0};
                for(auto j:moves[i]){
                    temp += dp1[j] % mod;
                    temp %= mod;
                }
                dp2[i]=temp%mod;
            }
            swap(dp1, dp2);
        }
        return accumulate(dp1.begin(), dp1.end(), 0, [](int sum, int cur) {return (sum + cur) % 1000000007;});
    }
};
