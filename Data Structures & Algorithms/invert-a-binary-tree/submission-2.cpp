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

#include <queue>
class Solution {
public:

// iterative solution
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return nullptr;
        }
        std::queue<TreeNode*> nodes{};
        nodes.push(root);
        while (!nodes.empty()){
            TreeNode* parent = nodes.front();
            nodes.pop();
            std::swap(parent->left, parent->right);
            if (parent->left){
                nodes.push(parent->left);
            }
            if (parent->right){
                nodes.push(parent->right);
            }
        }
        return root;


        
        

        }
    };
    