class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1{INT_MIN},sell1{0},buy2{INT_MIN},sell2{0};
        for(auto p: prices){
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1 + p);
            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return sell2;
    }
};
/*  Note that buying stock means we are spending money equivalent to the price of the stock,
*   thus subtract the price. On selling the stock we add the price because the associated 
*   price is getting added to our profit.

*   Final Profit = (Initial Profit — Buying Price) + Selling Price
*/
