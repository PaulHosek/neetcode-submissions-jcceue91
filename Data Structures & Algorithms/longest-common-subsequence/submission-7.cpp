class Solution {
public:

    /*
    bi-directional subsequence -> 1 string may be larger than the other
    
    random ideas:
    2 pointers, but need to compare prefixes
    take a, take b, skip a, skip b , not all combos valid
    Valid:
    take, take -> +1 in length
    skip skip -> don't see when this would be the case, have false and correct case already -> law of the excluded middle haha
    take skip -> +0
    skip take -> +0
    
    recurrance relation:
    if letters same take both if 
    
    */
    // gmax = 0
    // dp[i][j] = +1 if same
    
    int dfs(std::vector<std::vector<int>>& memo, std::string_view text1, std::string_view text2, int& gmax, int idx_t1, int idx_t2){
        if (idx_t1 == text1.size() || idx_t2 == text2.size()){
            return 0;
        }

        if (memo[idx_t1][idx_t2] != -1){
            return memo[idx_t1][idx_t2];
        }

        if (text1[idx_t1] == text2[idx_t2]){
            memo[idx_t1][idx_t2] = dfs(memo, text1, text2, gmax, idx_t1+1, idx_t2+1) +1;
        } else {
            int takeskip = dfs(memo, text1, text2, gmax, idx_t1+1, idx_t2);
            int skiptake = dfs(memo, text1, text2, gmax, idx_t1, idx_t2+1);
            memo[idx_t1][idx_t2] = std::max({takeskip, skiptake});
        }


        gmax = std::max(gmax, memo[idx_t1][idx_t2]);
        return memo[idx_t1][idx_t2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int gmax{0};
        std::vector<std::vector<int>> memo(text1.size(), std::vector<int>(text2.size(), -1));

        dfs(memo, text1, text2, gmax, 0, 0);
        return gmax;
    }
};
