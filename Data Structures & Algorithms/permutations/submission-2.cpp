class Solution {
public:

    void dfs(std::vector<int>&nums, int idx,std::vector<int>& tmp, std::vector<std::vector<int>>& res){
        if (nums.size() == tmp.size()){
            res.push_back(tmp);
            return;
        }



        tmp.push_back(nums[idx]);
        for (int i = 0; i < tmp.size(); i++){
            std::swap(tmp[i], tmp.back()); // swap with every position
            dfs(nums, idx+1, tmp, res);
            std::swap(tmp[i], tmp.back()); // swap back
        }
        tmp.pop_back();
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // if (nums.empty()){
        //     return {};
        // }
        std::vector<std::vector<int>> res{};
        std::vector<int> tmp{};
        // tmp.push_back(nums[0]);
        dfs(nums, 0, tmp, res);
        return res;
        
    }
};

// or std::itrswap(tmp.begin() + i, tmp.end());