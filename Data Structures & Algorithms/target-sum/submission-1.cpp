class Solution {
public:
    int dfs(const std::vector<int>& nums, const int cur, const int target, std::vector<std::vector<int>>& memo, int inum, const int shift){
        if (inum >= nums.size()){
            if (cur == target){
                return 1;
            }
            return 0;
        }

        if (memo[inum][shift + cur] != -1){
            return memo[inum][shift + cur];
        }

        int plus = dfs(nums, cur + nums[inum], target, memo, inum+1, shift);
        int minus = dfs(nums, cur - nums[inum], target, memo, inum+1, shift);

        return memo[inum][shift + cur] = plus + minus;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // 2d memo
        int shift = std::reduce(nums.begin(), nums.end());
        std::vector<std::vector<int>>memo(nums.size(), std::vector<int>(2* shift +1, -1));
        return dfs(nums, 0, target, memo, 0, shift);
        
    }
};
