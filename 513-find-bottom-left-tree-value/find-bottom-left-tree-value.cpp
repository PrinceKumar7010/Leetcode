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

   void lft(TreeNode* root ,int lvl,vector<int> &v,stack<int> &st){
       if(root==NULL)return ;
       if(lvl==st.size()){
           st.push(root->val);
           v.push_back(st.top());
       }
       lft(root->left,lvl+1,v,st);
       lft(root->right,lvl+1,v,st);



   }
    int findBottomLeftValue(TreeNode* root) {
       vector<int> v;
       stack<int> st;
int lvl=0;
      lft(root,lvl,v,st);
      int n=v.size()-1;
      return v[n];

    }
};