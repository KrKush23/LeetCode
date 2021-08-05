class Solution {
    int dp[101][201]; // i, M
    
    int helper(int i, int M, vector<int>& piles){
        // base
        if(i >= piles.size())   return 0;

        // look up
        if(dp[i][M] != -1)  return dp[i][M];

        int total = 0;
        int res = INT_MIN;
        
        for(int j=0; j<2*M; j++){
            if(i+j < piles.size()){
                total += piles[i+j];
                res = max(res, total - helper(i+j+1, max(M, 1+j), piles));
            }else{
                break;
            }
        }
        
        return dp[i][M] = res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        
        int diff = helper(0, 1, piles); // i=0, M=1
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        // sum  = A + B
        // diff = A - B
        // => A = (sum + diff)/2
        
        return (sum + diff)/2;
    }
};

 // NOTE : see STONE GAME III before this
