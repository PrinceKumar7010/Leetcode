class Solution {
public:
    void pre(TreeNode* root, int low, int high,int &sum){
  if(root==NULL)return;
  pre(root->left,low,high,sum);
  int t=root->val;
  if(t>=low && t<=high)sum+=t;
  pre(root->right,low,high,sum);

    }


    int rangeSumBST(TreeNode* root, int low, int high) {
    int sum=0;
    pre(root,low,high,sum);
    return sum;



    }
};