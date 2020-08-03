/*struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/

class MyHashSet {
private:
    TreeNode* root;
    vector<bool> elem;
    
public:
    /** Initialize your data structure here. */
    MyHashSet(){
        elem.resize(1E6 + 1);
    }
    
    void add(int key){
        elem[key] = true;
    }
    
    void remove(int key){
        elem[key] = false;
    }
    
    bool contains(int key){
        return elem[key];
    }
    
    /*MyHashSet() {
        root = nullptr;
    }
    
    void add(int key) {
        if (root){
            TreeNode* prev = nullptr;
            TreeNode* cur = root;
            
            while (cur){
                if (cur->val > key){
                    prev = cur;
                    cur = cur->left;
                } else if (cur->val < key){
                    prev = cur;
                    cur = cur->right;
                } else{
                    return;
                }
            }
            
            cur = new TreeNode(key);
            
            if (prev->val > key){
                prev->left = cur;
            } else{
                prev->right = cur;
            }
            
        } else{
            root = new TreeNode(key);
        }
    }
    
    void remove(int key) {
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        
        while (cur && cur->val != key){
            prev = cur;
            
            if (cur->val > key){
                cur = cur->left;
            } else{
                cur = cur->right;
            }
        }
        
        if (!cur) return;
        
        if (!cur->left && !cur->right){
            if (cur == root){
                root = nullptr;
            } else{
                if (prev->left == cur) prev->left = nullptr;
                else prev->right = nullptr;
            }
            
            delete cur;
        } else if (cur->left == nullptr || cur->right == nullptr){
            if (cur->left == nullptr){
                if (cur == root){
                    root = root->right;
                } else{
                    if (prev->left == cur) prev->left = cur->right;
                    else prev->right = cur->right;   
                }
            } else{
                if (cur == root){
                    root = root->left;
                } else{
                    if (prev->left == cur) prev->left = cur->left;
                    else prev->right = cur->left;
                }
            }
            
            delete cur;
        } else{
            TreeNode* tmp = cur->right;
            
            while (tmp->left) tmp = tmp->left;
            
            if (cur == root){
                root = tmp;
                root->left = cur->left;
                root->right = cur->right;
            } else{
                tmp->left = cur->left;
                tmp->right = cur->right;
                
                if (prev->left == cur) prev->left = tmp;
                else prev->right = tmp;
            }
            
            delete cur;
        }
    }
    
    /** Returns true if this set contains the specified element */
    /*bool contains(int key) {
        TreeNode* cur = root;
        
        while (cur){
            if (cur->val == key) return true;
            
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        
        return false;
    }*/
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
