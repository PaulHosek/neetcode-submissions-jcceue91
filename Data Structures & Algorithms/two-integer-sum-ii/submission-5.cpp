class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l{0};
        int r{numbers.size()-1};

        while (l < r){
            int tmp = numbers[l] + numbers[r];
            if(tmp < target){
                l++;
            } else if ( tmp > target){
                r--;
            } else {
                return {++l, ++r};
            }
        }
    }
};
