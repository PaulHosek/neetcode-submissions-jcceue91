
// You are given an integer array coins representing coins of different denominations (e.g. 1 dollar, 5 dollars, etc)\
//  and an integer amount representing a target amount of money.

// Return the number of distinct combinations that total up to amount. If it's impossible to make up the amount, return 0.
// You may assume that you have an unlimited number of each coin and that each value in coins is unique.
// - return 0 if not possible
// - may reuse coin
// - goal-> nr distinct combinations (7,2 == 2,7)
// - have a target value

// Example:
// Given coins [1,2,3] how to make 4.

// - start with can go from 3 to 4 by using 1
// - state = value remaining, 


class Solution {
public:

    // bool dfs(const int amount, vector<int>& coins, vector<bool>& cache, int& res){
    //     if (amount < 0){
    //         return false;
    //     }
    //     if (amount == 0 || cache[amount]){
    //         res++;
    //         return true;
    //     }
    //     // TODO: should cache only if there is a path with a coin to reach the amount
    //     // should also count all valid paths, so not overly prune. Prune enough to avoid duplicate paths

    //     bool gval = false;
    //     for(const int c : coins){
    //         bool valid = dfs(amount-c, coins, cache, res);
    //         if (valid){
    //             gval = true;
    //             cache[amount-c] = true;
    //         }

    //     }
    //     return gval; // there is a valid path from there 
    // }

    int dfs(const int amount, int icoin, std::vector<int>& coins, std::vector<std::vector<int>>& memo){
        if (amount == 0){
            return 1;
        }

        if (amount < 0 || icoin >= coins.size()){
            return 0;
        }
        if (memo[amount][icoin] != -1){
            return memo[amount][icoin];
        }

        int take = dfs(amount - coins[icoin], icoin, coins, memo);
        int skip = dfs(amount, icoin + 1, coins, memo);

        memo[amount][icoin] = take + skip;
        
        return memo[amount][icoin];


    }


    int change(int amount, vector<int>& coins) {

        std::vector<std::vector<int>> memo(amount+1, std::vector<int>(coins.size(), -1));
        return dfs(amount, 0, coins, memo);

        
    }
};

























