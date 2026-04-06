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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root){
            return {};
        }
        std::vector<std::vector<int>> out{};
        std::queue<TreeNode*> q{};
        q.push(root);
        while (!q.empty()){
            std::vector<int> lvl{};
            int qs = q.size();
            for (int i = 0; i < qs; i++){
                TreeNode* cur = q.front();
                if (cur->left){
                    q.push(cur->left);
                }
                if (cur->right){
                    q.push(cur->right);
                }
                lvl.push_back(cur->val);
                q.pop();
            }
            out.push_back(lvl);

        }
        return out;
    }
};
