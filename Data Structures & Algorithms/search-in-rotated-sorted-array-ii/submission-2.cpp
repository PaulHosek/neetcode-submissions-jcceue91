class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int N = nums.size();
        if (N == 0){
            return false;
        }
        int l{};
        int r{N-1};

        // find which side is sorted. If target in that range, go there, else go to the other side.
        while (l <= r){
            // find the pivot, then we know where to look
            int m = l + (r-l) /2;
            if (nums[m] == target){
                return true;
            }
            if (nums[l] == nums[m]){
                l++;
                continue;
            }

            if (nums[l] < nums[m]){ // left side is sorted, look on the right
                if (nums[l] <= target && nums[m] >= target){
                    auto it = std::lower_bound(nums.begin() + l, nums.begin() + m+1, target);
                    return  it != nums.begin() + m+1 && *it == target;
                    // search for the target in the sorted side.
                }
                // otherwise, target must be on the unsorted side
                l = m+1;
            } else { // right side is sorted, look on the 
                if (nums[r] >= target  && nums[m] <= target){
                    auto it = std::lower_bound(nums.begin() + m, nums.begin() + r+1, target);
                    return (it != nums.begin() + r+1 && *it == target);
                }
                r = m-1;

            } 

        }
        return false;
    }
};