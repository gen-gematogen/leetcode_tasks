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
/*class Solution {  MY CODE
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        TreeNode* bottom = root;
        TreeNode* top = root;
        stack<TreeNode*> nodes;
        
        while (top->right || bottom->left){
            while (bottom->left){
                bottom = bottom->left;
            }
            
            while (top != bottom){
                if (top->right){
                    nodes.push(top->right);
                    top->right = nullptr;
                }
                
                top = top->left;
            }
            
            if (top->right){
                nodes.push(top->right);
                top->right = nullptr;
            }
            
            if (!nodes.empty()){
                bottom->left = nodes.top();
                nodes.pop();
            }
        }
        
        bottom = root;
        
        while (bottom){
            bottom->right = bottom->left;
            bottom->left = nullptr;
            bottom = bottom->right;
        }
    }
};*/

class Solution{ //CLEANER CODE
public:
    void flatten(TreeNode* root){
        TreeNode* now = root;
        
        while (now){
            if (now->left){
                TreeNode* l = now->left;
                
                while (l->right){
                    l = l->right;
                }
                
                l->right = now->right;
                now->right = now->left;
                now->left = nullptr;
            }
            
            now = now->right;
        }
    }
    
};
