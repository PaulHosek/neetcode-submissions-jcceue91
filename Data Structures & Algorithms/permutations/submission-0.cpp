class Solution {
public:

    void dfs(std::vector<int>&nums, int idx,std::vector<int>& tmp, std::vector<std::vector<int>>& res){
        if (nums.size() == tmp.size()){
            res.push_back(tmp);
            return;
        }



        tmp.push_back(nums[idx]);
        dfs(nums, idx+1, tmp, res);
        for (int i = 0; i < tmp.size()-1; i++){
            std::iter_swap(tmp.begin()+i, tmp.end()-1); // swap with every position

            dfs(nums, idx+1, tmp, res);
            std::iter_swap(tmp.begin()+i, tmp.end()-1); // swap back
        }
        tmp.pop_back();
        

    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()){
            return {};
        }
        std::vector<std::vector<int>> res{};
        std::vector<int> tmp{};
        tmp.push_back(nums[0]);
        dfs(nums, 1, tmp, res);
        return res;
        
    }
};

// or std::itrswap(tmp.begin() + i, tmp.end());