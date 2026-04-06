class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();


        // std::vector<std::vector<int>> grid(n+1, std::vector<int>(m+1, 0));
        std::vector<int> row_below(m+1, 0);

        for(int r = n-1; r>=0; r--){
            int prev_diag = 0;
            for (int c = m-1; c>=0; c--){
                // need 3 values for a cell, the one below, the one left and the one diagonally below and left
                // row_below[c] -> below (not updated yet)
                // row_below[c+1] -> left (already updated to current row one up)
                // prev_diag -> previous value of c+1 before it was updated -> row below and one left
                int tmp = row_below[c];
                if (text1[r] == text2[c]){
                    row_below[c] = 1+ prev_diag;
                } else{
                    row_below[c] = std::max(row_below[c], row_below[c+1]);
                }
                prev_diag = tmp;
            }
        }
        return row_below[0];

    }
};
