#include <algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // cant come up with at better way than biary search over k and each evaluation brute force
        int upper_k {*std::max_element(piles.begin(), piles.end())};
        int lower_k {1};
        int mid_k {1};
        long long count {0};
        while (lower_k < upper_k){
            count = 0;
            mid_k = lower_k + (upper_k - lower_k) /2;
            // test if this k large enough

            for (const auto& p : piles){
                count += (p + mid_k - 1) / mid_k;
            }
            if (count <= h){
                upper_k = mid_k;
            } else {
                lower_k = mid_k + 1;
            }
        }
        return lower_k;        
        
    }
};
