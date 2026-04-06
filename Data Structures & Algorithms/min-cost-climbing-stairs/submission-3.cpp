class Solution {
public:
    int dfs(vector<int>& cost, int pos, vector<int>& memo){
        if(pos >= cost.size()){
            return 0;
        }
        if (memo[pos] != -1){
            return memo[pos];
        }



        memo[pos] = cost[pos] + std::min(dfs(cost, pos+1, memo), dfs(cost, pos+2, memo));
        return memo[pos];

    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        return std::min(dfs(cost,0, memo), dfs(cost, 1, memo));

    }
};
