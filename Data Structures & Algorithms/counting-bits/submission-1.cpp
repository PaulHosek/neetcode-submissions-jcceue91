class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n+1, 0);
        int off{0};
        for (int i = 1; i <= n; i++){
            // index needs to in 0,2,4,8,16... for me to increase the offset by that number
            // first it should be 0, then 2
            if ((i & (i-1)) == 0){
                off = i;
            }
            counts[i] = 1 + counts[i-off];
        }
        return counts;
        
    }
};
