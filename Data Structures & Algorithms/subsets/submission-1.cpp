class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& out, vector<int> tmp, int idx) {
        if (idx == nums.size()) {
            out.push_back(tmp);
            return;
        }
        
        dfs(nums, out, tmp, idx + 1);
        
        tmp.push_back(nums[idx]);
        dfs(nums, out, tmp, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        dfs(nums, out, {}, 0);
        return out;
    }
};