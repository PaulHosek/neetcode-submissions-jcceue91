class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) sum += n;

        // Edge cases: target is unreachable
        if (abs(target) > sum || (target + sum) % 2 != 0) return 0;

        int s = (target + sum) / 2;
        vector<int> dp(s + 1, 0);
        dp[0] = 1; // One way to make a sum of 0

        for (int num : nums) {
            // Iterate backwards to ensure each number is used only once
            for (int i = s; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[s];
    }
};
