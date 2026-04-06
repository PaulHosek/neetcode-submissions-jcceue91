
#include <array>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int r{};
        int l{};
        const int res_a = s1.length()-1;
        int res_b{};
        if (s1.length() > s2.length()){
        return false;
        }

        std::array<int, 26> freq1 {};
        std::array<int, 26> freq2 {};

        for (const auto el : s1){
            freq1[el - 'a']++;
        }
        for (const auto el : s2.substr(0,s1.length())){
            freq2[el - 'a']++;
        }

        if (freq1 == freq2){
            return true;
        }
    
        for (int r = s1.length(); r < s2.length(); r++, l++){
            
            freq2[s2[r] - 'a']++;
            freq2[s2[l] - 'a']--;


            if (freq1 == freq2){
                return true;
            }

        }
        return false;

        
    }
};
