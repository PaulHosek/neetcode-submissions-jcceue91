class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size() -1;
        int m =0;

        while (l <= r){

            m = l + (r - l) / 2;
            if (nums[m] == target){
                return m;
            }
            if (nums[l] > nums[m]){ // m is in right half
                if (target > nums[m] && target <= nums[r]){
                    l = m + 1;
                    // r--;
                } else {
                    r = m - 1;
                }
            } else if (target >= nums[l] && target < nums[m]){ // m is in left half
                r = m - 1;
                // l++;

            } else {
                l = m  + 1;
            }
            

        }
        return -1;
        
    }
};
