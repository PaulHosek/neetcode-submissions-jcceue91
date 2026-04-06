#include <ranges>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Frequency map building num : freq
        unordered_map<int, int> num_freq_map;
        for (int n : nums){
            num_freq_map[n]++;
        }
        // 2. invert buckets freq : {nums...}
        // at max all distinct frequencies
        vector<vector<int>> invert_bucket(nums.size()+1);
        for (const auto& [n, freq] : num_freq_map){
            invert_bucket[freq].push_back(n);
        }

        // 3. get the k most frequent
        std::vector<int> out{};
        for (const auto& vec : invert_bucket | std::views::reverse){
            for (int n : vec){
                out.push_back(n);
                if (out.size() == k){
                    return out;
                }
            }
        }
        return out;


        
    }
};
