class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2)
            return 0;
        int buy_0{0},buy_1{0},sell_0{0},sell_1{0},sell_2{0};
        buy_1 = -prices[0];
        buy_0 = max(buy_1,-prices[1]);
        sell_0 = max(sell_1, buy_1 + prices[1]);
        // space optimization
            sell_2 = sell_1;
            sell_1 = sell_0;
            buy_1 = buy_0;
        for(int i=2;i<n;i++){
            buy_0 = max(buy_1, sell_2 - prices[i]);
            sell_0 = max(sell_1, buy_1 + prices[i]);
            //space optimization
            sell_2 = sell_1;
            sell_1 = sell_0;
            buy_1 = buy_0;
        }
        return sell_0;
        //==================== USING VECTOR TO STORE DATA ===============
        /*
        vector<int> buy(n,0), sell(n,0);
        buy[0]=-prices[0];
        buy[1]=max(buy[0],-prices[1]);
        sell[1]=max(sell[0],buy[0]+prices[1]);
        for(int i=2;i<n;i++){
            buy[i] = max(buy[i-1], sell[i-2]-prices[i]);
            // buy[i-1] -> skipping buying stock
            // sell[i-2] -> or buying stock given we sold stock two days b4
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
            // sell[i-1] -> skipping selling stock
            // buy[i-1]+prices[i] -> selling stock 
        }
        return sell.back();
        */
    }
};
