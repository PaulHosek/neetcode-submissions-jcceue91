class Solution {
public:
    void dfs(int& res, vector<int>& cost, int pos, int c){
        if(pos > cost.size()){
            res = std::min(res, c);
            return;
        }
        if (c > res){
            return;
        }


        dfs(res, cost, pos+1, c + cost[pos]);
        dfs(res, cost, pos+2, c + cost[pos]);


    }

    int minCostClimbingStairs(vector<int>& cost) {
        int res{std::numeric_limits<int>::max()};
        // cost[0] = 0; // TODO look at this after
        // cost[0] = std::min(cost[0], cost[1]);
        // cost[1] = cost[0];
        dfs(res, cost, 0, 0);
        dfs(res, cost, 1, 0);
        return res;
    }
};
