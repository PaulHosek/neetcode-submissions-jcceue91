class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::unordered_map<int, int> complement;

      for (int i = 0; i< nums.size(); i++){
        auto it = complement.find(nums[i]);
        if (it != complement.end()){
            return {it->second, i};
        }
        complement[target - nums[i]] = i;
      }  
      return {};
    }
};
