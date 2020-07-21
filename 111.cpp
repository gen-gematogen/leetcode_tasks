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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        int len = INT_MAX;
        
        if (root->left){
            len = minDepth(root->left);
        } if (root->right){
            len = min(len, minDepth(root->right));
        }
        
        if (len == INT_MAX) return 1;
        
        return len + 1;
    }
};
