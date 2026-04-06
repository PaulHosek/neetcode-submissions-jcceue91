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
    vector<int> rightSideView(TreeNode* root) {
        // visible = right most node
        if (!root){
            return {};
        }
        std::vector<int> res{};
        std::queue<TreeNode*> q{};
        q.push(root);

        while(!q.empty()){
            int qs = q.size();
            TreeNode* rightmost = q.back();
            res.push_back(rightmost->val);
            // remove level and push next one
            for (int i = 0; i < qs; i++){
                TreeNode* node = q.front();
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
                q.pop();
            }
        }
        return res;

        
    }
};
