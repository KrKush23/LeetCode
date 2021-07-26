class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // GREEEDY ALGO ============================
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int res = 0;
        int cur = INT_MIN;
        
        for(auto pair: pairs){
            if(cur < pair[0]){
                cur = pair[1];
                res++;
            }
        }
        
        return res;     
        
        // DP - like LIS ==============================
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int n = pairs.size();
        vector<int> lis(n, 1);
        
        for (int i=0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(pairs[i][0] > pairs[j][1])
                    lis[i] = max(lis[i], lis[j] + 1);
                else
                    lis[i] = max(lis[i], lis[j]);
            }
        }
        return lis.back();
    }
};
