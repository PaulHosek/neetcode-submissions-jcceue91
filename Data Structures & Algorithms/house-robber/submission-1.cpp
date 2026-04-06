class Solution {
public:
    int rob(vector<int>& nums) {
        // either do i+1 & not add to sum or do i+2 and add to sum


        int c1{0};
        int c2{0};
        for (const auto& n : nums){
            // if want to add, need to skip the next one
            // either c1 or c2 are allowed to add every 2 steps
            c2 = std::max(c1, n + c2);
            std::swap(c1,c2);

        }

        return std::max(c1,c2);

        
    }
};
