/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* parent,  std::vector<int>& arr){
        if(!parent ){
            return;
        }

        dfs(parent->left, arr);
        arr.push_back(parent->val); // push back from left to right dfs
        dfs(parent->right, arr);

        // std::sort(arr.begin(), arr.end());
        // if (arr.size() == k){
        //     sml = arr[k-1];
        //     k = -1;
        //     return;
        // }


    }

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> arr{};
        dfs(root, arr);
        return arr[k-1];
        
    }
};
