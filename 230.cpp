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
/*class Solution {  //ITERATIVE
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        
        while (true){
            while (root){
                nodes.push(root);
                root = root->left;
            }
            
            root = nodes.top();
            nodes.pop();
            
            if (k-- == 1) return root->val;
            
            root = root->right;
        }
    }
};*/

/*class Solution{ MYRECURSIVE
public:
    int kthSmallest(TreeNode* root, int k){
        int v;
        
        int tmp = dfs(root, k, &v);
        
        return v;
    }
    
    int dfs(TreeNode* root, int k, int* v){
        if (root->left){
            k = dfs(root->left, k, v);
        }
        
        if (k-- == 1){
            *v = root->val;
            return k;
        }
        
        if (root->right){
            k = dfs(root->right, k, v);
        }
        
        return k;       
    }
};*/

class Solution{ //BEST TIME, avarage space
public:
    int kthSmallest(TreeNode* root, int k){
        vector<int> nodes;
        
        dfs(root, nodes);
        
        return nodes[k - 1];
    }
    
    void dfs(TreeNode* root, vector<int>& nodes){
        if (!root) return;
        
        dfs(root->left, nodes);
        
        nodes.push_back(root->val);
    
        dfs(root->right, nodes);
    }
};
