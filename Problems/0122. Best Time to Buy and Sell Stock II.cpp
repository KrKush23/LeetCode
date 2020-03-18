class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min{INT_MAX},max{min},diff{0},max_diff{0},profit{0};
        for(auto i:prices){
            if(i<max){
                min=max=i;
                profit+=max_diff;
                diff=max_diff=0;
            }
            else if(i>max){
                max=i;
                diff=max-min;
                if(diff>max_diff)
                    max_diff=diff;
            }
        }
        if(max_diff)
            profit+=max_diff;
        return profit;
    }
};
