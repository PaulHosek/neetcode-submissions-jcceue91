class Solution {
public:
    int dp_scan(const vector<int>& nums){
        int c1{0};
        int c2{0};
        for (const auto& n : nums){
            c2 = std::max(c1, c2 + n);
            std::swap(c1,c2);
        }
        return std::max(c1,c2);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        const vector<int>& left{nums.begin()+1, nums.end()};
        const vector<int>& right{nums.begin(), nums.end()-1};
        return std::max(dp_scan(left), dp_scan(right));
    }
};
