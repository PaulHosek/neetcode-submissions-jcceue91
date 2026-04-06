
// given w1 and w2, make w2 out of w1
// left = incorrect word pointer, right = target word pointer
// insert, replace, delete
// insert = move right only, leave left in place
// replace = move both pointers
// delete = move left only 

// cache state with left right and the fill in nr operations so far
class Solution {

public:
    int dfs(const string& word1, const string& word2, std::vector<std::vector<int>>& memo_min_operation_count, const int maxops, int current, int reference){
        if (current >= word1.length() || reference >= word2.length()){
            // OOB and invalid path
            // mark invalid path with large number but be cautious of overflow
            // since we have insert and delete, the cost of the remaining path is the remaining nr of chars
            return current < word1.length() ? word1.length() - current : word2.length() - reference;

        }

        if (memo_min_operation_count[current][reference] != maxops){
            return memo_min_operation_count[current][reference];
        }

        int minpath{maxops};
        if (word1[current] != word2[reference]){
            const int replace =  1 + dfs(word1, word2, memo_min_operation_count, maxops, current+1, reference+1); // replace
            const int del =  1 + dfs(word1, word2, memo_min_operation_count, maxops, current+1, reference);   // delete 
            const int inse = 1 + dfs(word1, word2, memo_min_operation_count, maxops, current, reference+1);   // insert
            minpath = std::min({replace, del, inse});
        } else {
            // matching, no operation needed
            minpath = dfs(word1, word2, memo_min_operation_count,maxops, current+1, reference+1);
        }

        memo_min_operation_count[current][reference] = minpath;
        cout << minpath << " ";
        return minpath;

    }
    int minDistance(string word1, string word2) {
        const int maxops = word1.length() + word2.length() + 2;
        std::vector<std::vector<int>> memo_min_operation_count(word1.length()+1, std::vector<int>(word2.length()+1, maxops));
        return dfs(word1, word2, memo_min_operation_count, maxops, 0, 0);
    }
};
