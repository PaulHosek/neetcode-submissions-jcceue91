class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        std::vector<int> prefix(n+1, 0); // negative numbers
        for (int i = 0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        int count{};
        for (int pi = 0; pi < n; pi++){
            for (int si = pi; si <n; si++){
                if (prefix[si+1] - prefix[pi] == k){
                    count++;
                }
            }
        }
        return count;

    }
};