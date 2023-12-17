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
class Solution {
public:
    int mxdepth(TreeNode* root){
     if(root==NULL)return 0;

     int left=mxdepth(root->left);
     int right=mxdepth(root->right);

     return max(left,right)+1;




    }
    int maxDepth(TreeNode* root) {
       return mxdepth(root);

    }
};