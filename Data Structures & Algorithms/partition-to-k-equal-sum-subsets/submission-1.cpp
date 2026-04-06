class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        const int N = nums.size();
        const int total = std::accumulate(nums.begin(), nums.end(), 0);
        const int target = total/ k;
        if (N == 0 || total % k != 0){
            return false;
        }


        std::ranges::sort(nums);
        std::ranges::reverse(nums);
        std::vector<bool> visited(N, 0);
        auto dfs = [&](auto self, int cur_sum, int start_i, int ki)->bool{
            if (ki == k-1){
                return true;
            }
            if (cur_sum == target){
                return self(self, 0, 0, ki+1);
            }

            for (int i = start_i; i<N; i++){

                if (visited[i] || nums[i] + cur_sum > target){
                    continue;
                }

                visited[i] = true;

                if(self(self, cur_sum + nums[i], i+1, ki)){
                    return true;
                }

                visited[i] = false;
                if (cur_sum == 0){
                    return false;
                }
            }
            return false;

        };

        return dfs(dfs, 0,0,0);


    }
};