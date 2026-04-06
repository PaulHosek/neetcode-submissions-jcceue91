#include <vector>
#include <algorithm>
#include <iterator> // For std::distance

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        // --- 1. Find the Potential Row using std::upper_bound ---

        // std::upper_bound searches for the first element *greater* than target.
        // We search in the column of first elements (matrix[i][0]).
        // To use it, we use a custom comparison lambda to compare 'target'
        // with the *first element* of each row vector.
        
        auto it_row = std::upper_bound(
            matrix.begin(), 
            matrix.end(), 
            target,
            [](const int target_val, const std::vector<int>& row) {
                // Compare the target_val with the first element of the row
                return target_val < row[0];
            }
        );

        // 'it_row' will now point to the first row whose first element is > target.
        // The potential row that might contain 'target' is the one *immediately before* 'it_row'.
        
        // If it_row is matrix.begin(), it means the target is smaller than matrix[0][0], so it's not present.
        if (it_row == matrix.begin()) {
            return false;
        }

        // Move the iterator back one position to get the actual row to search.
        --it_row; 

        // --- 2. Search the Row using std::binary_search ---

        const std::vector<int>& row = *it_row;
        
        // std::binary_search checks if an element exists in a sorted range.
        return std::binary_search(row.begin(), row.end(), target);
    }
};