class Solution {
    int mod = 1e9+7; 
public:
    int countVowelPermutation(int n) {
        // SIMPLE APPROACH =====================
        vector<long long> dp(5, 1);
        // A -> E
        // E -> A,I
        // I -> A,E,O,U
        // O -> I,U
        // U -> A
        for(int k=2; k<=n; k++){
            long long a=dp[0], e=dp[1], i=dp[2], o=dp[3], u=dp[4];
            dp[0] = (e + i + u) % mod; // A can come after E,I,U
            dp[1] = (a + i) % mod;     // E can come after A,I
            dp[2] = (e + o) % mod;     // I can come after E,O
            dp[3] = (i) % mod;         // O can come after I
            dp[4] = (i + o) % mod;     // U can come after I,O
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % mod;
    }
};
