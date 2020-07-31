/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        bool tmp = findNode(pathP, root, p);
        tmp = findNode(pathQ, root, q);
        
        reverse(pathP.begin(), pathP.end());
        reverse(pathQ.begin(), pathQ.end());
        
        int len = min(pathP.size(), pathQ.size());
        int i = 0;
        
        for (; i < len; ++i){
            if (pathP[i]->val != pathQ[i]->val) break;
        }
        
        return pathP[i - 1];
    }
    
    bool findNode(vector<TreeNode*>& path, TreeNode* root, TreeNode* target){
        if (!root) return false;
        
        if (root == target){
            path.push_back(root);
            return true;
        }
        
        if (findNode(path, root->left, target) || findNode(path, root->right, target)){
            path.push_back(root);
            return true;
        }
        
        return false;
    }
};
