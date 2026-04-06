class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();


        // std::vector<std::vector<int>> grid(n+1, std::vector<int>(m+1, 0));
        std::vector<int> row(m+1, 0);

        for(int r = n-1; r>=0; r--){
            int prev_diag = 0;
            for (int c = m-1; c>=0; c--){
                int tmp = row[c];
                if (text1[r] == text2[c]){
                    row[c] = 1+ prev_diag;
                } else{
                    row[c] = std::max(row[c], row[c+1]);
                }
                prev_diag = tmp;
            }
        }
        return row[0];

    }
};
