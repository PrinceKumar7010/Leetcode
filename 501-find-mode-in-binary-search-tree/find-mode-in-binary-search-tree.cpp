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
    unordered_map<int,int> mp;
    void pre(TreeNode* root){
        if(!root)return ;
     pre(root->left);
     int q=root->val;
     mp[q]++;
     pre(root->right);



    }
    

    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        pre(root);int mx=INT_MIN;
        for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
        if(i.second>mx)mx=i.second;
        }
        for(auto i:mp){
       if(i.second==mx)v.push_back(i.first);
        }

        
        return v;
    }
};