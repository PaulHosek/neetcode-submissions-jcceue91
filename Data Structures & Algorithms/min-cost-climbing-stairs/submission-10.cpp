class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // base case: wirte after general case
        const int n = cost.size();
        if (n <= 3){
            return std::min(cost[1], cost[0] + std::min(cost[1], cost[2]));
        }

        std::vector<int> cheapest_at(n);
        cheapest_at[n-1] = cost[n-1];
        cheapest_at[n-2] = cost[n-2];
        for (int i = n-3; i >= 0; i--){
            cheapest_at[i] = cost[i] + std::min(cheapest_at[i+1], cheapest_at[i+2]);
        }

        // can start at 0 or 1
        return std::min(cheapest_at[0], cheapest_at[1]);
        
    }
};
