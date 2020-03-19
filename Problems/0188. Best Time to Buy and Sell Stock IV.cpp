class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //CASE 1: Can't Perform Any Transactions
        if(n<2 or k<1)              
            return 0;
        //CASE 2: K > Floor(N/2)
        if(k > n/2){               
            int profit{0};
            for(int i=1;i<n;i++)
                profit += max(0,prices[i]-prices[i-1]);
            return profit;
        }
        //CASE 3: K < Floor(N/2)                       
        vector<int> buy(k,INT_MIN), sell(k,0);
        for(auto p:prices){
            buy[0] = max (buy[0], -p);
            sell[0] = max (sell[0], buy[0]+p);
            for(int i=1;i<k;i++){
                buy[i] = max(buy[i], sell[i-1] - p);
                sell[i] = max(sell[i], buy[i] + p);
            }
        }
        return sell[k-1];
    }
};
/*============================ Case 2 EXPLAINED ==================================
*   if we have N days of stocks given, we can do at most floor(n/2) transactions
*
*   so when k > floor(n/2), then we can do as many transactions as we want
*   thus we calculate profit in this case very easily
*
*   THIS CASE WAS USED AS MEMORY LIMIT EXCEEDED WHEN K WAS LARGE AND WE COULDN'T
*   MAKE AN ARRAY THAT BIG . Eg - 10^9
*/
