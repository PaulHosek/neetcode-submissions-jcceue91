class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, int idx, vector<int>& tmp){
        if(nums.size() == idx){
            res.push_back(tmp);
            return;
        }


        tmp.push_back(nums[idx]);
        dfs(nums, res, idx+1, tmp);
        tmp.pop_back();

        while (idx+1 < nums.size() && nums[idx] == nums[idx+1]){
            idx++;
        }
        dfs(nums, res, idx+1, tmp);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp{};
        std::vector<vector<int>> res{};
        std::sort(nums.begin(), nums.end());
        dfs(nums, res, 0, tmp);

        return res;


    }
};
