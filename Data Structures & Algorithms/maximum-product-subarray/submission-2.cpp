/* Given an integer array nums, 
find a subarray that has the largest product within the array and return it.
 - product of adjacent numbers
 - array can contain negative numbers
    - two negatives is one positive
    - how to track that negatives may come later
 - without negatives the whole array would always be the answer (except 0)
 - 0 is not a neutral number -> maps downwards
    - what is a neutral number? -> 1 is identity here
 - traversal direction irrelevant
    

A subarray is a contiguous non-empty sequence of elements within an array.
- subarray must not be empty
- subarray must be contiguous


You can assume the output will fit into a 32-bit integer
- assume signed is meant
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_res{nums[0]};
        int min_res{nums[0]};
        int global_max{nums[0]};
        int prev_max{};

        for (int i{1}; i<nums.size(); i++){
            // if choose against including i, then cannot do res * i in the next
            // do all cases with include number and then update global
            prev_max = max_res;

            max_res = std::max(min_res*nums[i], std::max(prev_max*nums[i], nums[i]));
            min_res = std::min(prev_max*nums[i], std::min(min_res*nums[i], nums[i]));

            global_max = std::max(max_res, global_max);

        }
        return global_max;
    }
};





