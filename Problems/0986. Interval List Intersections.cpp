class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans{};
        int n = A.size(), m = B.size();
        int i{0}, j{0};
        while(i<n and j<m){
            int right_bound = min(A[i][1], B[j][1]);
            int left_bound  = max(A[i][0], B[j][0]);
            if(left_bound <= right_bound)
                ans.push_back({left_bound, right_bound});
            
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};
