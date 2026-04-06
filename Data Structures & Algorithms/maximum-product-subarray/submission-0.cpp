
#include <limits>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int res = std::numeric_limits<int>::min();
       int curmin = 1;
       int curmax = 1;
       
       for (int n : nums){
        int oldmx = n*curmax;
        curmax = std::max(n, std::max(oldmx, n * curmin));
        curmin = std::min(n, std::min(oldmx, n * curmin));
        res = std::max(res, curmax);
       }
       return res;


    }
};
