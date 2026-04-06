class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int,int> prefix_count{};

        int cur_total{0};
        int count{0};
        prefix_count[0] = 1;
        for (int i = 0; i<nums.size(); i++){

            cur_total += nums[i];

            int complement = cur_total - k;
            if (prefix_count.find(complement) != prefix_count.end()){
                count += prefix_count[complement];
                
            }
            prefix_count[cur_total]++;

        }
        return count;
    }
};