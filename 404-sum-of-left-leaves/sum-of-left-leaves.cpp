class Solution {
public:
    int res=0;
    void dfs(TreeNode* root,int z){
     
     if(root==NULL)return ;
     if(root->left==NULL && root->right==NULL){
     if(z==1)res+=root->val;}
     dfs(root->left,1);
     dfs(root->right,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int z=-1;

        dfs(root,z);
        return res;



    }
};