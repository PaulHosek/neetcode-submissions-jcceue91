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

    void dfs(TreeNode* parent,  int& cnt, int k, int& res){
        if(!parent || res != -1){
            return;
        }

        dfs(parent->left, cnt, k, res);
        cnt++;
        if (cnt == k){
            res = parent->val;
            return;
        }
        dfs(parent->right, cnt, k, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count{}; // could also reuse this
        int res{-1};
        dfs(root, count, k, res);
        return res;
    }
};
