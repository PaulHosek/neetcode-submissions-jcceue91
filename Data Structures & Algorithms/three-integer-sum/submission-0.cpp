class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1 outer pointer + 2 inner pointers
        sort(nums.begin(), nums.end());
        int end {static_cast<int>(nums.size()-1)};
        int out_left {0};
        int l {0};
        int r = end;
        vector<vector<int>> found;
        while (out_left < end-1){
            if (nums[out_left] >0){
                break;
            }
            if (out_left > 0){
                if (nums[out_left-1]==nums[out_left]){
                    out_left++;
                    continue;
                }
            }
            l = out_left+1;
            r = end;
            while (l < r){
                int cur_sum = nums[out_left] + nums[l] + nums[r];
                if (cur_sum < 0){
                    l++;
                } else if(cur_sum > 0){
                    r--;
                } else {
                    found.push_back({nums[out_left], nums[l], nums[r]});
                    l++;
                    r--;
                    while (nums[l] == nums[l-1] and l < r){
                        l++;
                    }

                }
            }
            out_left++;
        }
        return found;
    }
};
