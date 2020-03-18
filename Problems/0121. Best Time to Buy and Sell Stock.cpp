class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min{INT_MAX},max{min},diff{0},max_diff{0};
        for(auto i: prices){
            if(i<min){
                min=max=i;
                diff=0;
            }
            else if(i>max){
                max=i;
                diff=max-min;
                if(diff>max_diff)
                    max_diff=diff;
            }
        }
        return max_diff;
    }
};
