class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur{0};
        int gmax{nums[0]};
        for (int i = 0; i< nums.size(); i++){
            cur += nums[i];
            gmax = std::max(cur, gmax);

            cur *= (cur >= 0);


        }
        return gmax;
    }

};
