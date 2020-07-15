class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0){
            return nullptr;
        }

        return buildBST(nums, 0, nums.size());
    }
private:
    TreeNode* buildBST(vector<int>& nums, int l, int r){
        int m = (l + r) / 2;

        TreeNode* root = new TreeNode(nums[m]);

        if (m != l){
            root->left = buildBST(nums, l, m);
        } 
        if ((m + 1) != r){
            root->right = buildBST(nums, m + 1, r);
        }

        return root;
    }
};
