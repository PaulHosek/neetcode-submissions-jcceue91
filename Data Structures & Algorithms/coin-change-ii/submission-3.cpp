class Solution {
public:


    int change(int amount, vector<int>& coins) {
        std::vector<std::vector<int>> memo(coins.size(), std::vector<int>(amount+1, -1));

        auto dfs = [&](auto self, int idx, int rem){
            if (rem == 0) {return 1;}
            if (idx >= coins.size()) {return 0;}

            if (memo[idx][rem] != -1){
                return memo[idx][rem];
            }

            // skip
            unsigned int ways = self(self, idx +1, rem);

            // take
            if (rem >= coins[idx]){
                ways += self(self, idx, rem - coins[idx]);
            }

            memo[idx][rem] = ways;
            return memo[idx][rem];
        };

        return dfs(dfs, 0, amount);
    }
};