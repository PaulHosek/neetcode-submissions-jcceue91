class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // inverted if can only use coin once?

        std::vector<uint64_t> counts(amount+1, 0);

        counts[0] = 1;

        for (int c : coins){
            for (int j = c; j<amount+1;j++){
                if (j-c >= 0){
                    counts[j] += counts[j - c];
                }
            }

        }
        return counts[amount];
        
    }
};