


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int shift = std::reduce(nums.begin(), nums.end());
        std::vector<std::vector<int>> memo(nums.size(), std::vector<int>(2*shift+1, -1));
        std::function<int(int, int)> dfs = [&](int inum, int cursum) -> int {
            if (inum >= nums.size()){
                if (cursum == target){
                    return 1;
                }
                return 0;
            }

            if (memo[inum][cursum+shift] != -1){
                return memo[inum][cursum+shift];
            }

            int plus = dfs(inum+1, cursum + nums[inum]);
            int minus = dfs(inum+1, cursum - nums[inum]);

            return memo[inum][cursum+shift] = plus + minus;

        };
        return dfs(0, 0);
    }
};
