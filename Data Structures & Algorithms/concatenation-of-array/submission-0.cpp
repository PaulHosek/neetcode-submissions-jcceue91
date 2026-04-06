class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> out;
        const int n = nums.size();
        out.reserve(2*n);
        for (int w = 0; w < 2; w++){
            for (int n : nums){
                out.push_back(n);
            }
        }
        return out;
    }
};