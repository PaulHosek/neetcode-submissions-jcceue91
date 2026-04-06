class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x{0};
        for (const int n : nums){
            x ^= n;
        }
        return x;
        
    }
};
