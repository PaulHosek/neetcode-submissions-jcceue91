class Solution {
public:
    bool isPalindrome(string s) {
        
        int l{0};
        int r(s.length()-1);
        while (l < r){
            // move left pointer until we see a letter or nr
            while(l < r && !std::isalnum(s[l])){
                l++;
            }
            while(r > l && !std::isalnum(s[r])){
                r--;
            }

            if (r != l && std::tolower(static_cast<const unsigned char>(s[r])) != std::tolower(static_cast<const unsigned char>(s[l]))){
                return false;
            }
            l++;
            r--;
        }
        return true;

    }
};
