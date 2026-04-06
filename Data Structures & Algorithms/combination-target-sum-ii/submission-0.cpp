class Solution {
public:

    void dfs(vector<int>& candidates, int target, vector<int>& tmp, int idx, int cursum, vector<vector<int>>& res){
        if (cursum == target && std::find(res.begin(), res.end(), tmp) == res.end()){
            res.push_back(tmp);
            return;
        }

        if(idx == candidates.size() || cursum > target){
            return;
        }

        dfs(candidates, target, tmp, idx+1, cursum, res);
        tmp.push_back(candidates[idx]);
        dfs(candidates, target, tmp, idx+1, cursum+candidates[idx], res);
        tmp.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res{};
        std::vector<int> tmp{};
        dfs(candidates, target, tmp, 0, 0, res);
        return res;
        
    }
};
