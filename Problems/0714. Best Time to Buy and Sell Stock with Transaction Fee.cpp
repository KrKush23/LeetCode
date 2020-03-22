class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n<2)
            return 0;
        //============== SPACE OPTIMIZATION =================
        int buy = -prices[0]-fee, sell = 0, lastbuy;
        for(int i=1;i<n;i++){
            lastbuy = buy;
            buy = max(lastbuy, sell -prices[i] -fee);
            sell = max(sell, lastbuy + prices[i]);
        }
        return sell;
        //========= USING VECTOR TO STORE DATA ==============
        /*
        vector<int> buy(n,0), sell(n,0);
        buy[0]=-prices[0]-fee;
        for(int i=1;i<n;i++){
            buy[i]= max(buy[i-1],sell[i-1]-prices[i]-fee);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
        }
        return sell.back();
        */
    }
};
