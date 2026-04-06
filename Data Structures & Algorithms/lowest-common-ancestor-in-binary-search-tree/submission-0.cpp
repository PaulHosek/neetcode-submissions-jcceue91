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
        int vp = p->val;
        int vq = q->val;

        while(true){
            if (!node){
                return lca;
            }
            const auto& val = node->val;
            if (vp == val || vq == val){
                return lca;
            }
            if (vp < val || vq < val){
                if (vp >= val || vq >= val){
                    // on both sides or cur node
                    return node;
                } else {
                    node = node->left;
                    lca = node;
                }
           } else {
                node = node->right;
                lca = node;
            }
           
           
            
        }


        
    }
};
