class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
           return abs(a[0] - a[1]) > abs(b[0]-b[1]); 
        });
        int sum1{}, sum2{}, cnt1{}, cnt2{}, n = costs.size();
        int i=0;
        while(i<n and cnt1 < n/2 and cnt2 < n/2){
            if(costs[i][0] < costs[i][1]){
                sum1 += costs[i++][0];
                cnt1++;
            }else{
                sum2 += costs[i++][1];
                cnt2++;
            }
        }
        while(cnt1 < n/2){
            sum1 += costs[i++][0];
            cnt1++;
        }
        while(cnt2 < n/2){
            sum2 += costs[i++][1];
            cnt2++;
        }
        return sum1 + sum2;
    }
};
