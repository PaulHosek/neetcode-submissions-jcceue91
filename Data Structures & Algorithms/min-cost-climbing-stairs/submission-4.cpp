class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2){
            return std::min(cost[0],cost[1]);
        }
        if (cost.size() == 0){
            return 0;
        }

        // -2 last positions stay the same
        
        for (int i = cost.size()-3; i>=0; i--){
            cost[i] += std::min(cost[i+1], cost[i+2]);
        }
        return std::min(cost[0],cost[1]);
    }
};
