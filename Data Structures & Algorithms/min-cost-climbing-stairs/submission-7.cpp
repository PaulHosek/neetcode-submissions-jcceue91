class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1){
            if (cost.empty()){
                return 0;
            } else {
                return cost[0];
            }
        }

        int c1 = cost[cost.size()-1];
        int c2 = 0; // position after the end has no cost
        for (int i = cost.size()-2; i>=0; i--){
            // shift c2 in next iteration to be c2 (cur c1)
            std::swap(c1,c2); 

            c1 = cost[i] + std::min(c1,c2);


        }
        return std::min(c1,c2);
    }
};
