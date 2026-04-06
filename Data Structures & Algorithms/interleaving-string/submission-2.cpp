// You are given three strings s1, s2, and s3. Return true if s3 is formed by interleaving s1 and s2 together or false otherwise.

// Interleaving two strings s and t is done by dividing s and t into n and m substrings respectively, where the following conditions are met

// |n - m| <= 1, i.e. the difference between the number of substrings of s and t is at most 1.
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// Interleaving s and t is s1 + t1 + s2 + t2 + ... or t1 + s1 + t2 + s2 + ...
// You may assume that s1, s2 and s3 consist of lowercase English letters.

// - s1 and s2 must make up s3
// - order must be same 
// - may take either from left or from right 
// - return if possible


// - use 2 pointers
//  - branch at each ambiguous decision point
//  - don't branch if there is not decision to made and just advance the correct pointer
// - at end s1 and s2 pointers must be at end and same with s3 pointer

class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        const auto s1l = s1.length();
        const auto s2l = s2.length();
        const auto s3l = s3.length();

        if (s1l + s2l != s3l){
            return false;
        }
        if (s1l + s2l + s3l == 0){
            return true;
        }

        std::vector<std::vector<bool>> memo(s1l+1, std::vector<bool>(s2l+1, false));
        bool res{false};
        std::function<void(int, int, int)> dfs = [ &](int p1, int p2, int p3)->void{

            if (p1 == s1l && p2 == s2l && p3 == s3l){
                res = true;
            }
            if (res || memo[p1][p2]){
                return;
            }
            bool valid_s1 = (p1 < s1l) && (s1[p1] == s3[p3]);
            bool valid_s2 = (p2 < s2l) && (s2[p2] == s3[p3]);
            if (valid_s1){
                dfs(p1+1, p2, p3+1);
            }
            if (valid_s2){
                dfs(p1, p2+1, p3+1);
            }
            memo[p1][p2] = true;

            
        };
        dfs(0,0,0);
        
        return res;
    }

};
