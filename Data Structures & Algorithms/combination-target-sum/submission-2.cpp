class Solution {
public:
    void dfs(vector<vector<int>>& out, vector<int> const& nums, const int target, vector<int>& temp, int cursum, int idx){
        // base case: if sum is met, add temp vector
        if (cursum == target){
            out.push_back(temp);
            return;
        }
        
        // condition for early stopping: if target cannot be reached cur_sum > target
        if (cursum > target || idx == nums.size()){
            return;
        }
        // choices: take and stay OR skip (must have option that allws taking multiple times and option that allows taking never) 
        
        dfs(out, nums, target, temp, cursum, idx+1);// skip
        temp.push_back(nums[idx]);
        dfs(out, nums, target, temp, cursum + nums[idx], idx); // take and stay
        temp.pop_back();

        // backtrack: undo the take if we did it
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        vector<int> temp;
        dfs(out, nums, target, temp, 0, 0);
        return out;

    }
};
// all possible combos where numbers in nums sum up to target
    // avoid infinite recursion -> prune if target cannot be reached anymore
        // -> all numbers are guaranteed > 0 so not infinite possiblities

// can choose each number multiple times -> 1 choice must pick and stay