class Solution {
public:


    int maxSubarraySumCircular(vector<int>& nums) {
        
        // allow expansion until l-1
        const int N = nums.size();
        int l = 0;
        int r = 0;
        int best{nums[1]};
        int cur{};

        int cur_min{};
        int best_min{};

        int total{};
        for (int num : nums){
            cur = std::max(cur+num, num);
            best = std::max(cur, best);
            
            cur_min = std::min(cur_min+num, num);
            best_min = std::min(best_min, cur_min);
            total += num;
        }

        if (best < 0){
            return best;
        } 
        return std::max(total - best_min, best);









    }
};