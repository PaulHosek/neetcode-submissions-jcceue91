#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> umap;
        
        // for (auto it= nums.begin(); it!= nums.end(); ++it)
        for (const auto & elem : nums){
            std::cout << elem << "\n";
            auto x = umap.find(elem);
            if (x == umap.end()){
                umap[elem] = 1; // could make key the count or index if wanted that functionality
            }
            else {
                return true;
            }

        }
        return false;
    


    }
};
