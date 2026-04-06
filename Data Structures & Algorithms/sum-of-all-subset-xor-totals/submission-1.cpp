class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total{0};
        for (int n : nums){
            total |= n;
        }
        return total << (nums.size() -1);
    }
};