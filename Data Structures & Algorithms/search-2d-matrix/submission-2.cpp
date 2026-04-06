#include <algorithm>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low {0};
        int high (matrix.size()-1);
        int mid {0};
        int row_last = matrix[0].size()-1;
        int row_mid{0}; 
        // search for the row
        while (low <= high){
            mid = low + (high - low)/2;
            if (target < matrix[mid][0]){
                high = mid -1;
            } else if (target > matrix[mid][row_last]){
                low = mid + 1;
            } else {
                low = 0;
                high = row_last;
                const auto& row = matrix[mid];

                bool found = std::binary_search(row.begin(), row.end(), target);
                return found;
                // while (low <= high){
                //     row_mid = low + (high - low)/ 2;
                //     const auto& row = matrix[mid];
                //     if (target < row[row_mid]){
                //         high = row_mid -1;
                //     } else if (target > row[row_mid]){
                //         low = row_mid + 1;
                //     } else{
                //         return true;
                //     }
                // }
                return false;
            }
        }   
        return false;
    }
};
