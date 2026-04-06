class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n+1, 0);
        for (int i = 1; i <= n; i++){
            // index needs to in 0,2,4,8,16... for me to increase the offset by that number
            // first it should be 0, then 2
            counts[i] = 1+ counts[(i & (i-1))];
        }
        return counts;
        
    }
};
