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

    void dfs(TreeNode* parent, int& cnt, int curmax){
        if(!parent){
            return;
        }
        if (curmax <= parent->val){
           cnt++; 
        }
        curmax = std::max(parent->val, curmax);

        dfs(parent->left, cnt, curmax);
        dfs(parent->right, cnt, curmax);

    }
    int goodNodes(TreeNode* root) {
        int cnt{};
        dfs(root, cnt, root->val);
        return cnt;
        
    }
};
