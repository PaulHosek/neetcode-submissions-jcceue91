#include <limits>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount+1, amount+1); // does not work if amount is the max integer, then will wrap around at +1 and give wrong result
       dp[0] = 0;

       for (int a = 1; a <= amount; a++){
        for (int c : coins){
            int x = a-c;
            if (x >= 0){
                dp[a] = min(dp[a], 1 + dp[a-c]); // update the fastest known path
            }
        }
       }
       return dp[amount] != amount+1 ? dp[amount] : -1;

    }
};
