class Solution {
public:
    void solve(TreeNode* root, bool &flag, int num) {
        if(root == NULL)
        return;

        if(root -> val != num)
        flag = false;

        solve(root -> left, flag, num);
        solve(root -> right, flag, num);
    }
    bool isUnivalTree(TreeNode* root) {
        int num = root -> val;
        bool flag = true;
        solve(root, flag, num);
        return flag;
    }
};