#include <iostream>
#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        std::array<int, 26> char_hist = {0};
        for (int i = 0; i<s.size(); i++){
            char_hist[s[i] - 'a']++; 
            char_hist[t[i] - 'a']--;
        }
        for (auto count : char_hist){
            std::cout << count << std::endl;
            if (count != 0) {
                return false;
            }
        }
        return true;


        
        
    }
};
