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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* node = root;
        TreeNode* lca = node;
        int pv = p->val;
        int qv = q->val;

        while(true){
            int nv = node->val;
            if (pv > nv && qv > nv){
                node = node->right;
            } else if (pv < nv && qv < nv){
                node = node->left;
            } else {
                return node;
            }
        }
    }
};
