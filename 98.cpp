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
private:
    bool dfs(TreeNode* root, int min, int max){
        if (!root) return true;
        
        if (root->val < min || root->val > max) return false;

        bool valid = true;

        if (root->left){
            if (root->left->val < root->val)
                valid &= dfs(root->left, min, root->val - 1);
            else 
                return false;
        }      
    
        if (root->right){
            if (root->right->val > root->val)
                valid &= dfs(root->right, root->val + 1, max);
            else 
                return false;
        }
        
        return valid;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);        
    }
};
