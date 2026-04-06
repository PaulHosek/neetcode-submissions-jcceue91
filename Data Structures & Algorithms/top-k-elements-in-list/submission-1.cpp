class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_count;
        for (const auto& n : nums){
            num_count[n]++;
        }
        vector<vector<int>> freq(nums.size()+1);// will sort by index
        for (auto& [n, f]:num_count){
           freq[f].push_back(n);
        }
        vector<int> out;
        for (int i = nums.size(); i >0 && i<freq.size(); i--){
            auto f = freq[i];
            for (const auto& v : f){
                out.push_back(v);
                if(out.size() == k){
                    return out;
                }
            }
        }
        return out;
        
    }
};
