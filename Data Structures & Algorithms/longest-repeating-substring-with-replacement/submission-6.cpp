#include <array>
#include <ranges>
class Solution {
public:
    int characterReplacement(string s, int k) {
        std::array<int, 26>alph{};
        int l{};
        int r{};
        int res{};
        while (r < s.length()){
            alph[s[r] - 'A']++;
            if ((r - l +1) - (*std::max_element(alph.begin(), alph.end())) <= k){ // can I compensate the rest of the window where not the most frequent char with k
                // size of window -> best one so far
                res = std::max(res, r-l+1);
                r++;
            } else {
                alph[s[l] - 'A']--;
                l++;
                r++;
            }
        }
        return res;
        
        
    }
};
