
// given 2 strings s and t
// s must be >= t. 
// order must be preserved


// approach
// 2d matrix: s x t
// insert 1 in first column
// for each cell look if can go diagonally down (move to next) -> if so, insert a 1 in that cell
// if cannot go diagonally down, go down if then we have a match and increase cur_cell + 1 in that cell
//  => going diagonally -> no choice
//  => going down is -> +1 choice
// Last step: sum up last column -> last column are leaf nodes of the tree

// just noticed that this can lead to invalid paths if e.g., bba and bba -> then would get 2 because start at second b and reach end
// only start in the first column! this should solve this

// just noticed that if we intersect a branching path (i.e., one that went down at a least once), 
//  then we need to multipy that path weight with the one we have

class Solution {
public:

    int dfs(const string& s, const string& t, std::vector<std::vector<int>>& memo,
     const size_t tlen, const size_t slen, int r, int c){

        if (r == tlen){
            return 1; // valid path
        }
        if (c == static_cast<int>(slen)){
            return 0;
        }
        if (r < 0 || c < 0 || r >= tlen || c >= slen){
            return 0; // invalid path, does not reach last column
        }

        if (memo[r][c] != -1){
            // TODO: if met path that has already been visited, need to do +1 down that path for all values
            // 
            // WANT: If path insersects node that has already been visited and reaches the end
            // , I want to stop there and just update the total
            // // do not want to have to travel down that path again
            // could convert memo into -1, true, false and only mark true on backtracking
            return memo[r][c];
        }
        int count = 0;


        count += dfs(s, t, memo, tlen, slen, r, c+1);
        if (t[r] == s[c]){
           // try diagonal and down
           count += dfs(s, t, memo, tlen, slen, r+1, c+1);
           // need to backtrack here, add the right pathweight to the cell in the memo so that we can multipy paths together

        }
        memo[r][c] = count;
        return count;
    }

    int numDistinct(string s, string t) {
        if (s.length() < t.length()){
            return 0;
        }
        const size_t tlen = t.length();
        const size_t slen = s.length();
        // t rows (short) and s columns (long)
        std::vector<std::vector<int>> memo(tlen, std::vector<int>(slen, -1));
        return dfs(s,t, memo, tlen, slen, 0,0);


    }
};
