class Solution {
public:
    vector<int> v;
    int i = 0;

    void in(TreeNode* root) {
        if (root == NULL) return;
        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }

    void newin(TreeNode* root) {
        if (root == NULL) return;
        newin(root->left);
        root->val = v[i++];
        newin(root->right);
    }

    void recoverTree(TreeNode* root) {
        in(root);
        sort(v.begin(), v.end());
        i = 0; 
        newin(root);
    }
};