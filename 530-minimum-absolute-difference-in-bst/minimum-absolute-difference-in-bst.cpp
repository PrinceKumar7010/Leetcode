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
vector<int> s;
void pre(TreeNode* root){
if(root==NULL)return;
pre(root->left);
pre(root->right);
s.push_back(root->val);

}
    int getMinimumDifference(TreeNode* root) {
       pre(root);
       int mn=INT_MAX;
       sort(s.begin(),s.end());
       for(int i=0;i<s.size()-1;i++){
       mn=min(mn,s[i+1]-s[i]);

       } 
       return mn;
    }
};