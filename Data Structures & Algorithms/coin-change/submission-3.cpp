class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INVALID = amount+1;
        std::ranges::sort(coins);
        std::ranges::reverse(coins);
        std::vector<int> memo(amount+1, INVALID);
        // coin & amount to count

        auto dfs = [&](auto self, long long cur)->int{
            if (cur > amount){
                return -1;
            }
            if (cur == amount){
                return 0;
            }

            if (memo[cur] != INVALID){
                return memo[cur];
            }

            int min_coins = INVALID;

            for (int c : coins){
                int res = self(self, cur + c);

                if (res != -1){
                    min_coins = std::min(min_coins, res+1);
                }
            }

            memo[cur] = min_coins == INVALID ? -1 : min_coins;
            return memo[cur];
        };

        return dfs(dfs, 0);
    }
};
