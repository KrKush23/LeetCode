class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n<2) return n;
        
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1]; // sort a/c to RIGHT
        });
        
        int res{1}, last{pairs[0][1]};
        for(int i=1; i<n; i++){
            if(pairs[i][0] > last){
                res++;
                last = pairs[i][1];
            }
        }
        return res;        
    }
};
