#include <unordered_map>
#include <vector>
#include <string>
#include <array>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> umap;
        for (auto& s : strs){
            std::array<int, 26> bins {0};
            for (auto& c : s){
                bins[c - 'a']++;
            }
            // convert array to string
            std::string key;
            for (auto& count : bins){
                key += std::to_string(count) + ",";
            }
            umap[key].push_back(s); // [] will create a key if it does not exist yet

        }
        std::vector<std::vector<std::string>> out;
        for (auto& [key,value]: umap){
            out.push_back(value);
        }
        return out;



    }
};
