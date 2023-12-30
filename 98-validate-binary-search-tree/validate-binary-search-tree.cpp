class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTHelper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true; // Base case: leaf nodes are valid BSTs
        }

        if (root->val <= lower || root->val >= upper) {
            return false; // Check if the current node's value is within the valid range
        }

        // Recursively check the left and right subtrees
        return isValidBSTHelper(root->left, lower, root->val) &&
               isValidBSTHelper(root->right, root->val, upper);
    }
};
