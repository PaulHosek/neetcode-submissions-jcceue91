class Solution {
public:


    /*
    - array of integers & target
    - each arr[i] can do + or - to total
        - state is identified by location in array & cursum
    - find nrways to sum up to target
    
    random ideas:
    - what's a small state? -> choin change like-> could find sum for small amount first than larger amounts
        - small state2: smaller array-> what if combos for small subarray and then extend?
            - could do this for all sums, then see if rest is available with those

    - when is taget not reachable -> if no positives and smaller and if no negative and larger is obvious case
    - draw it out

    - take and minus vs. take and plus
    - state is both location and cursum (equivalently: leftover)
        - sparse, don't do grid-> umap(K={idx, sum}, V = nrcombos here)

    fill first with 1
    for (idx > 1 in nums){

        for (sums that we build so far)
            nrwayscache[at the sum before - curidx nr ] // sparse, cannot use vector
            nrwayscache[at the sum before + curidxnr ]
            // basically use this as a column of the possibilities of at i-1, then move idx one and update all possible states at that level with ours


    }
    return nrwayscache[target]


    -- 
    
    
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.empty()){
            if (target == 0){
                return 1;
            }
            return 0;
        }

        std::unordered_map<int,int> nrWaysCache; 
        std::unordered_map<int, int> nrWaysCache_before;


        nrWaysCache_before[0] = 1;
        for (int n : nums){
            // now after one itr, we need to push the combo array forward
            for (const auto& [sum_before, combo_before] : nrWaysCache_before){
                // this only works if the new state is clean
                nrWaysCache[sum_before - n] += combo_before;
                nrWaysCache[sum_before + n] += combo_before;
            }
            std::swap(nrWaysCache_before, nrWaysCache); 
            nrWaysCache.clear();
        }


        // due to swap
        return nrWaysCache_before[target];

    }
};
