class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice{INT_MAX}, maxProfit{0};
        for(auto i: prices){
            if(i<minPrice)
                minPrice=i;
            else if(i-minPrice > maxProfit)
                maxProfit = i - minPrice;
        }
        return maxProfit;
    }
};
