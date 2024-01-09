class Solution {
public:
    vector<int>v1;
    vector<int>v2;
void p1(TreeNode* root){

    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL)v1.push_back(root->val);
    p1(root->left);
    p1(root->right);
}
void p(TreeNode* root1){

    if(root1==NULL)return;
    if(root1->left==NULL&&root1->right==NULL)v2.push_back(root1->val);
    p(root1->left);
    p(root1->right);
}


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        p(root1);
        p1(root2);
       if(v1==v2)return true;
        return false;


    }
};