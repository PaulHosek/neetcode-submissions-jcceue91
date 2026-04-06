class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 2 pointers, both start at 0
        // keep track of total
        // if total > 0, then continue expanding
        // if total < 0 , move l and right to the position after the negative
        if (nums.empty()){
            return 0;
        }
        int l{1};
        int r{1};
        int gmax{nums[0]};
        int cur{nums[0]};

        while (r < nums.size()){

            if (cur < 0){
                l = r;
                cur = nums[r];
            } else {
                cur += nums[r];
            }
            r++;
            gmax = std::max(gmax, cur);
        }

        return gmax;

    }
};
