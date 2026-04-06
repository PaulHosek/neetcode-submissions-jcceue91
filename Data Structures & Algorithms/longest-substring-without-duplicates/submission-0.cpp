#include <unordered_set>
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen{};

        int l{0};
        int r{0};
        const int slen = s.length();
        int longest{};
        while (r < slen){
            if (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            } else {
                seen.insert(s[r]);
                r++;
                longest = std::max(longest, r-l);
            }

        }
        return longest;
        
        
    }
};

// s="abcabcbb"
// lv = c
// rv = b
// set {c}
// longest = 1 | 2 | 3 | 
