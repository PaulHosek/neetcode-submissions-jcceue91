class NumArray {
public:
    NumArray(vector<int>& nums) : prefix_sum_(nums.size()+1, 0){
        for (int i = 0; i<nums.size(); i++){
            prefix_sum_[i+1] = prefix_sum_[i] + nums[i];
        }


    }
    
    int sumRange(int left, int right) {
        // inclusive and may overlap
        return prefix_sum_[right+1] - prefix_sum_[left];

    }
private:
std::vector<int> prefix_sum_;

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */