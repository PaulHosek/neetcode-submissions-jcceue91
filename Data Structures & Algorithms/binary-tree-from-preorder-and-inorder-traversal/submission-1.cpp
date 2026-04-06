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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);

        // index of root in inorder = mid
        auto itr = std::find(inorder.begin(), inorder.end(), preorder[0]);
        int mid = std::distance(inorder.begin(), itr);

        vector<int> leftpreorder(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> leftinorder(inorder.begin(), inorder.begin() + mid);

        vector<int> rightpreorder(preorder.begin()+mid+1, preorder.end());
        vector<int> rightinorder(inorder.begin()+mid+1, inorder.end());


        root->left = buildTree(leftpreorder, leftinorder);
        root->right = buildTree(rightpreorder, rightinorder);

        return root;


        
    }
};
