class Solution {
private:
     int pathCnt = 0;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
       countPaths(root, 0);
       return pathCnt;
    }
private:
    void countPaths(TreeNode * root, int currPath){
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL){
            currPath ^= (1 << root->val);
            if((currPath & (currPath - 1)) == 0)pathCnt++;
        }
        currPath ^= (1 << root->val);
        countPaths(root->left, currPath);
        countPaths(root->right, currPath);
    }    
};