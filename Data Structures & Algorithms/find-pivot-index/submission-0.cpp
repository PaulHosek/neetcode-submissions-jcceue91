class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total{};
        for (const int nr : nums){
            total+= nr;
        }
        int left_sum{};
        for (int i = 0; i<nums.size(); i++){
            int right_sum = total - left_sum - nums[i];

            if (right_sum == left_sum){
                return i;
            }
            left_sum += nums[i];
        }
        return -1;

        
    }
};