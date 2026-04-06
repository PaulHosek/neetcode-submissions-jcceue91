/* You are given an array of integers cost where 
cost[i] is the cost of taking a step from the ith floor of a staircase. 
After paying the cost, you can step to either the (i + 1)th floor or the (i + 2)th floor.
- if are on ith step must add cost[i]
- can do i+1 or i+2

You may choose to start at the index 0 or the index 1 floor.
- can start at idx 0 or 1

Return the minimum cost to reach the top of the staircase, 
i.e. just past the last index in cost.
- must reach position n+1 exactly
- overshooting is incorrect
- minimize cost

cost = [1,2,3]

Decision: Find the minimal cost to get to pos n

Invert: 
cost from position n-4 is
-> cost[n-4] = min(cost[n-4+1], cost[n-4+2])

cost from position n-3 is
-> cost[n-3] = min(cost[n-3+1], cost[n-3+2]);

cost from position n-2 onwards is cost[n-2] -> basecase 1
cost from position n-1 must is cost[n-1] -> basecase 2
*/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 2){
            if (cost.empty()){
                return 0;
            }
            return *std::min_element(cost.begin(), cost.end());
        }

        const int n = cost.size();
        int cost_2up{cost[n-1]};
        int cost_1up{cost[n-2]};
        for (int i = n-3; i>=0; i--){
            int cur = cost[i] + min(cost_1up, cost_2up);
            // window will move
            cost_2up = cost_1up;
            cost_1up = cur;

        }
        return std::min(cost_1up, cost_2up); // will be first 2 values
        
    }
};
