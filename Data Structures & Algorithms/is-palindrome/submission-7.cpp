class Solution {
public:
    bool isPalindrome(string s) {

        int l {0};
        int r {static_cast<int>(s.size())-1};

        while (l < r){
            while (l < r && !isalnum(s[l])){
                l++;
            }
            while (l < r && !isalnum(s[r])){
                r--;
            }

            if (tolower(s[l]) != tolower(s[r]) && l <r){
                return false;
            }
            l++;
            r--;


        }

        return true;
        
    }
};

// l = 0
// r = 26
// s[l] = w
// s[r] == w
