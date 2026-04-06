#include <unordered_set>
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen_elems{};
        int l{};
        int r{};
        int max_found{};
        const int slen = s.length();
        while (r < slen){
            if (seen_elems.find(s[r]) != seen_elems.end()){
                seen_elems.erase(s[l]);
                l++;
            } else {
                seen_elems.insert(s[r]);
                r++;
                max_found = std::max(max_found, r-l);

            }
        }
        return max_found;
        
    }
};
