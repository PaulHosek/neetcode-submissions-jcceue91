#include <numeric>
class Solution {
public:

    void dfs(vector<int>& nums, vector<int>& tmp, int target, vector<vector<int>>& res, int idx, int curSum){
        if (target == curSum){
            res.push_back(tmp);
            return;
        }

        if (idx >= nums.size() || curSum>target){
           return; 
        }


        dfs(nums, tmp, target, res, idx+1, curSum);
        tmp.push_back(nums[idx]);
        dfs(nums, tmp, target, res, idx, curSum + nums[idx]);
        tmp.pop_back();

        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res{};
        std::vector<int> tmp{};
        dfs(nums, tmp, target, res, 0,0);
        return res;
        
    }
};
