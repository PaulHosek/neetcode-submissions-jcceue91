#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> number_count_umap;
        vector<vector<int>> counts(nums.size()+1);

        for (auto n : nums){
            number_count_umap[n]++;
        }
        for (const auto& [n, c] : number_count_umap){
            counts[c].push_back(n);
        }
        int j = 0;
        std::vector<int> out(k);
        for (int i = counts.size() - 1; i > 0; --i){
            for (int v : counts[i]){
                out[j] = v;
                j++;
                if (j == k){
                    return out;
                }
            }
        }
        return out;




        
    }
};
