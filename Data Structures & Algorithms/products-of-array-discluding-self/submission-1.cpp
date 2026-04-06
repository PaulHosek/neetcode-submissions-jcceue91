class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> out(n,1);

        int prod=nums[0];
        for (int i = 1; i<n; i++){
            out[i] = prod;
            prod *= nums[i];
        }
        // prod = 8*6 = 48
        // [1, 1,2,8]

        int prod_back = nums[n-1];
        for (int i = n-2; i>=0; i--){
            out[i] *= prod_back;
            prod_back *= nums[i];
        }
        // prod_back = 6*4 = 24
        // [48,24,12,8]
        return out;

    }
};
