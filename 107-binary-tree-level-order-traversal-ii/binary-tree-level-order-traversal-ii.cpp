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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) {
        return {} ;
    }
      queue<TreeNode*> q;
      q.push(root);
      vector<vector<int>> ans;

      while(q.size()>0){
      int n=q.size();
      vector<int> v;
      while(n>0){
      TreeNode* temp=q.front();
      q.pop();
      v.push_back(temp->val);
      if(temp->left!=NULL)q.push(temp->left);
      if(temp->right!=NULL)q.push(temp->right);
      n--;
      }
      ans.push_back(v);
      }
      reverse(ans.begin(),ans.end());
      return ans;  
    }
};