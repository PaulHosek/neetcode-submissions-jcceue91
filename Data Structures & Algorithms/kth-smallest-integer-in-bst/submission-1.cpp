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

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> arr{};
        dfs(root, arr, k);
        return arr[k-1];
    }


    void dfs(TreeNode* parent,  std::vector<int>& arr, int k){
        if(!parent || arr.size() == k){
            return;
        }

        dfs(parent->left, arr, k);
        arr.push_back(parent->val); // push back from left to right dfs
        dfs(parent->right, arr, k);


    }

};
