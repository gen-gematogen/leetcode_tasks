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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        return travers(root, ans);

        return ans;
    }

private:
    void travers(TreeNode* root, vector<int>& ans){
        if (root != nullptr){
            travers(root->left, ans);
            ans.push_back(root->val);
            travers(root->right, ans);
        }

        return;
    }

};
