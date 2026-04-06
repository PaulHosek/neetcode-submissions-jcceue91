// // You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
// - array of prices integers all of them
// // You may CAN_BUY and sell one NeetCoin multiple times with the following restrictions:

// // After you sell your NeetCoin, you cannot buy another one on the next day (i.e., there is a cooldown period of one day).
// // You may only own at most one NeetCoin at a time.
// // You may complete as many transactions as you like.
// - Goal: maximise profit: price_sell - price_buy
// - can have only 1 coin at at time
// - cannot sell on i+1 if buy on i
//     - take or skip like dp
//     - branching condition is take and do +2 or skip with +1

// // Return the maximum profit you can achieve.

// prices = [1,3,4,0,4]

// - if we do backwards




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // dp[day][state]
        // State 0: Ready to BUY
        // State 1: Holding stock, ready to SELL
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        constexpr int READY_TO_BUY = 0;
        constexpr int HOLDING_STOCK = 1;

        for (int day = n - 1; day >= 0; day--) {
            
            // READY_TO_BUY
            // Option A: Buy today -> move to HOLDING state tomorrow
            // Option B: Skip today -> stay in READY_TO_BUY state tomorrow
            int buy_now = dp[day + 1][HOLDING_STOCK] - prices[day];
            int wait_to_buy = dp[day + 1][READY_TO_BUY];
            dp[day][READY_TO_BUY] = max(buy_now, wait_to_buy);

            // HOLDING_STOCK
            // Option A: Sell today -> move to READY_TO_BUY after a 1-day cooldown (day + 2)
            // Option B: Hold longer -> stay in HOLDING state tomorrow
            int sell_now = prices[day] + dp[day + 2][READY_TO_BUY]; 
            int keep_holding = dp[day + 1][HOLDING_STOCK];
            dp[day][HOLDING_STOCK] = max(sell_now, keep_holding);
        }

        return dp[0][READY_TO_BUY];
    }
};










// class Solution {
// public:

//     int dfs(const vector<int>& prices, int cur_profit, vector<int>& profit_at, int i, int last_coin){
//         if (i < 0){
//             return cur_profit;
//         }

//         if (profit_at[i] != -1){
//             return profit_at[i] + cur_profit;
//         }
//         // take
//         // profit_at[i] = std::max(profit_at[i+2] + last_coin - prices[i]]);
//         int res1 = dfs(prices,cur_profit + (last_coin - prices[i]), profit_at, i-2, prices[i]);
//         // skip
//         // do nothing and go back one
//         int res2 = dfs(prices,cur_profit, profit_at, i-1, last_coin);
//         prices[i] = std::max(res1, res2) - cur_profit;
//         return 
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n < 3){
//             return 0;
//         }
//         std::vector<int> profit_at(n, -1);
//         return dfs(prices,0, profit_at, n-1, 0);
//         // return profit_at[0];
//     }
// };


        // int n = prices.size();
        // for (int i = n-1; i>=0; i--){

        // }
 