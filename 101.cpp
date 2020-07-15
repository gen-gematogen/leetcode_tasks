class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr){
            return true;
        }

        queue<TreeNode*> que;

        if (root->left != nullptr && root->right != nullptr){
            que.push(root->left);
            que.push(root->right);

            while (!que.empty()){
                TreeNode* l = que.front();
                que.pop();
                TreeNode* r = que.front();
                que.pop();

                if (l->val == r->val){
                    if (l->left != nullptr && r->right != nullptr){
                        que.push(l->left);
                        que.push(r->right);
                    } if (l->right != nullptr && r-> left != nullptr){
                        que.push(l->right);
                        que.push(r->left);
                    } if (l->left != nullptr && r->right == nullptr || l->left == nullptr && r->right != nullptr ||
                    l->right != nullptr && r->left == nullptr || l->right == nullptr && r->left != nullptr){
                        return false;
                    }
                } else{
                    return false;
                }
            }

            return true;
        }

        return false;
    }
};
