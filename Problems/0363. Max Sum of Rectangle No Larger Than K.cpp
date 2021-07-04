class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int res{INT_MIN};
        int rows = mat.size();
        int cols = mat[0].size();
        
        // BASIC ===========================================
        for(int l=0; l<cols; l++){
            vector<int> sums(rows);
            for(int r=l; r<cols; r++){
                for(int i=0; i<rows; i++)
                    sums[i] += mat[i][r];
                                
                set<int> s{0}; //PREFIX SUM (sorted)
                int run_sum = 0;
                for(int sum: sums){
                    run_sum += sum;
                    cout<<run_sum - k<<"\n";
                    auto it = s.lower_bound(run_sum - k); 
                    if(it != s.end())
                        res = max(res, run_sum - *it);
                        // run_sum - (run_sum -k) ==>  k  ==> max <= k
                    s.insert(run_sum);
                }
            }
        }
        return res;
      
        // WITH KADANE
        for(int l=0; l<cols; l++){
            vector<int> sums(rows);
            for(int r=l; r<cols; r++){
                int kadane {0}, max_kadane {INT_MIN};
                for(int i=0; i<rows; i++){
                    sums[i] += mat[i][r];
                    kadane = max(kadane + sum[i], sum[i]);
                    max_kadane = max(max_kadane,kadane);
                }
                if(max_kadane <= k){
                    res = max(res, max_kadane);
                    continue;
                }
                
                set<int> s{0}; //PREFIX SUM (sorted)
                int run_sum = 0;
                for(int sum: sums){
                    run_sum += sum;
                    cout<<run_sum - k<<"\n";
                    auto it = s.lower_bound(run_sum - k); 
                    if(it != s.end())
                        res = max(res, run_sum - *it);
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};
