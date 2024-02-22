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
    int height(TreeNode* root,int &x){
    if(root==NULL)return 0;

    int left=height(root->left,x);
    int right=height(root->right,x);
    if(abs(left-right)>1)x++;
    return max(left,right)+1;

    }
   

    bool isBalanced(TreeNode* root) {


int x=0;
    int p=height(root,x);
   if(x>0)return false;
   return true; 
    
    }
};