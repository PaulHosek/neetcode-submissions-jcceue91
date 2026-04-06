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
    void dfs_subtree(TreeNode* tree, TreeNode* subtree, bool& candiate){
       if(!subtree || !tree){
        if (subtree || tree){
            candiate = false; 
        }
        return;
       }

       if (tree->val != subtree->val){
        candiate = false;
        return;
       }

       dfs_subtree(tree->left, subtree->left, candiate);
       dfs_subtree(tree->right, subtree->right, candiate);

    }


    void dfs_root(TreeNode* parent, TreeNode* subRoot, bool& valid){
        if (!parent){
            return;
        }

        if (parent->val == subRoot->val){
            bool candidate{true};
            dfs_subtree(parent->left, subRoot->left, candidate);
            dfs_subtree(parent->right, subRoot->right, candidate);
            if (candidate){
                valid = true;
                return;
            }
        }
        

        dfs_root(parent->left, subRoot, valid);
        dfs_root(parent->right, subRoot, valid);




    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot){
            return true; // if subtree root is nullptr we know that it must be a subtree
        }
        bool valid{false};
        dfs_root(root, subRoot, valid);
        return valid;



        
    }
};
