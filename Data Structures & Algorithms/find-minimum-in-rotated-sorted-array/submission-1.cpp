class Solution {
public:
    int findMin(vector<int> &nums) {
        int l {};
        int r = nums.size()-1;
        int mid{};
        int res{nums[0]}; 

        while (l <= r){
            // if r < l then we know that the array is perfectly sorted and left must be the smallest value

            if (nums[l] < nums[r]){
                return std::min(res, nums[l]);
            }

            mid = l + (r - l) /2;
            res = std::min(res, nums[mid]);
            // if l < mid -> left side ->check right side from pivot
            if (nums[l] <= nums[mid]){
                l = mid + 1;
            // otherwise check left side
            } else {
                r = mid - 1;  
            }
        }
        return res;
    }
};


    // const last_i = nums.size()-1
    // int upi = std::maximum_element(nums.begin(), nums.end());
    // int lowi = upi + 1 % last_i;
    // int midi {0};

    // const int rot = upi;
    // while (((lowi - rot )% last_i) < ((upi - rot) % last_i)){
        
    //     midi = 
    // }
