// can do i^j to check if duplicate
// 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // i gives the average expected value of any num in nums

        int res = nums.size();
        for (int i =0; i<nums.size(); i++){
            res -= nums[i] - i;
        }
        return res;
    }
};
