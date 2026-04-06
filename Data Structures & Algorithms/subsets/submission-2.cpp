class Solution {
public:


    void dfs(int idx, std::vector<int>& cur, std::vector<std::vector<int>>& out,const std::vector<int>& nums){
        // base case, choices,condition, backtrack(push, dfs,pop)

        // base case: end of the list
        if (idx == nums.size()){
            out.push_back(cur);
            return;
        }

        // choices: include next subset or not
        // condition: always
        // skip
        dfs(idx+1, cur, out, nums);

        // take
        cur.push_back(nums[idx]);
        dfs(idx+1, cur, out, nums);

        // backtrack
        cur.pop_back();



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> out;
        std::vector<int> tmp;
        dfs(0, tmp, out, nums);
        return out;
    }
};
