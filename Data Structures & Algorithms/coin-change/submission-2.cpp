
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {

//         if (amount == 0){
//             return 0;
//         }

//         // reccurance relation: find coins to make up small amount
//         vector<int> nrcoins(amount+1, amount+1);
//         nrcoins[0] = 0;
//         for (int a = 1; a <=amount; a++){
//             for (int c : coins){
//                 if (c <= a){
//                     // +1 if want to use the coin from below
//                     nrcoins[a] = std::min(nrcoins[a], nrcoins[a - c] + 1);
//                 }
//             }
//         }
//         return nrcoins[amount] == amount+1 ? -1 : nrcoins[amount];
        
//     }
// };

#include <algorithm>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int out{amount+1};
        // counts for this coin, amount combo
        const int n_coins = coins.size();
        std::vector<std::vector<int>> coin_amount_memo(n_coins, std::vector<int>(amount+1, amount+1));
        std::ranges::sort(coins, std::greater<>());
        auto dfs = [&](auto self, int i, int cur_amount, int cur_count){
            if (cur_amount == amount){
                out = std::min(cur_count, out);
            }

            // if there is no way to have fewer coins
            if (i == n_coins || cur_count + (amount - cur_amount) / coins[i] >= out){
                return;
            }

            if (coin_amount_memo[i][cur_amount] <= cur_count){
                return;
            }
            coin_amount_memo[i][cur_amount] = cur_count;
            


            // take or skip the coin
            if (cur_amount + coins[i] <= amount){
                self(self, i, cur_amount + coins[i], cur_count+1);
            }
            self(self, i+1, cur_amount, cur_count);
        };

        dfs(dfs, 0, 0, 0);
        return out == amount+1 ? -1 : out;
    }
};
