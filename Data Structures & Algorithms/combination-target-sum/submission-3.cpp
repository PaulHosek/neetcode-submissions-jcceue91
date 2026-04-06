class Solution {
public:
    

    void dfs(std::vector<int> const& nums, std::vector<std::vector<int>>& out, int target, int i, int cursum, std::vector<int>& curvec){
        if (cursum >= target){
            if (cursum == target){
                out.push_back(curvec);
            }
            return;
        }
        if (i == nums.size()){
            return;
        }

        curvec.push_back(nums[i]);
        dfs(nums, out, target, i, cursum + nums[i],curvec);
        curvec.pop_back();
        dfs(nums, out, target, i+1, cursum, curvec);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> out;
        std::vector<int> curvec;
        dfs(nums, out, target, 0, 0, curvec);
        return out;
        

    }
};
