class Solution {
public:
    // Reduced the problem to a subset sum problem:
    // Write problem as there are 2 sets: one of Positives P and one of to be
    // subtracted positive numbers N
    // 1. Each solution there exists T is made up like : T = sum(P) - sum (N)
    // 2. We need to use all numbers: sum(nums) = sum(N) + sum(P)
    // subsitituting sum(N) = sum(nums) - sum(P)
    // we get: sum(P)=(target+sum)/2 

    int findTargetSumWays(vector<int>& nums, int target) {


        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);


        // Edge cases: target is unreachable
        // 1. if total sum is smaller than abs of target, even doing all - or all + cannot reach it
        // e.g., target = 10 but total sum is 6
        // 2. Know that sum(P) cannot be a fraction since it is a sum of integers
        if (std::abs(target) > total_sum || (target + total_sum) % 2 != 0){
            return 0;
        }
        // if fulfilled, target is reachable

        // S is the subset sum we need to find
        int s = (target + total_sum) / 2;
        vector<int> dp(s + 1, 0);
        dp[0] = 1; // One way to make a sum of 0

        // for each number
        // skip over all where i < num because then num would not fit into i
        // iterate and 
        for (int num : nums) {
            // Iterate backwards to ensure each number is used only once
            for (int i = s; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[s];
    }
};
