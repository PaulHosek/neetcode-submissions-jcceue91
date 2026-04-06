#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        std::unordered_map<char, short> countS;
        std::unordered_map<char, short> countT;
        for (int i = 0; i < s.length(); i++){
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;

        
    }
};
