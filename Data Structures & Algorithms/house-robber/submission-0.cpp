class Solution {
public:
    int rob(vector<int>& nums) {
        // either do i+1 & not add to sum or do i+2 and add to sum

        if (nums.size() <= 2){
            if (nums.empty()){
                return 0;
            }
            return *std::max_element(nums.begin(), nums.end());
        }

        const int n = nums.size();
        int c1(nums[n-1]);
        int c2(0);
        for (int i = n-2; i >=0; i--){
            // if want to add, need to skip the next one
            // either c1 or c2 are allowed to add every 2 steps
            c2 = std::max(c1, nums[i] + c2);
            std::swap(c1,c2);

        }

        return std::max(c1,c2);

        
    }
};
