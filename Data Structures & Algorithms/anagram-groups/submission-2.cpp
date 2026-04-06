#include <unordered_map>
#include <string>
#include <vector>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<std::string, std::vector<std::string>> anagrams;

        for (auto s : strs){
            std::array<int, 26> anag = {};
            for (auto c : s){
                anag[c - 'a']++;
            }
            // convert array to string key
            std::string key;
            for (auto i : anag){
                key += i + ',';
            }
            anagrams[key].push_back(s); // [] will create if do not exist
        }
        std::vector<std::vector<std::string>> out;
        for (auto [key, value] : anagrams){
            out.push_back(value);
        }
        return out;
    }
};
