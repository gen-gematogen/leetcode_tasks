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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        
        vector<int> values = {root->val};
        
        vector<int> left = largestValues(root->left);
        vector<int> right = largestValues(root->right);
        
        int n = min(left.size(), right.size());
        
        for (int i = 0; i < n; ++i){
            values.push_back(max(left[i], right[i]));
        }
        
        if (left.size() > right.size()){
            for (int i = n; i < left.size(); ++i){
                values.push_back(left[i]);   
            }
        } else if (left.size() < right.size()){
            for (int i = n; i < right.size(); ++i){
                values.push_back(right[i]);
            }
        }
        
        return values;
    }
};
