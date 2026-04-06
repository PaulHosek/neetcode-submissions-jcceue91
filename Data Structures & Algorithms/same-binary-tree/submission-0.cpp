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

    void dfs(TreeNode* parent_p, TreeNode* parent_q, bool& same){
        if (!parent_q || !parent_p){
            if (parent_q || parent_p){ // structure different, one is not nullptr
                same = false;
            }
            return;
        }
            
        
        dfs(parent_p->right, parent_q->right, same);
        dfs(parent_p->left, parent_q->left, same);

        if (parent_p->val != parent_q->val){ // value different
            same = false;
        }
        return;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same{true};
        dfs(p, q, same);
        return same;
        
    }
};
