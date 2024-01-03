class Solution {
public:
    vector<vector<int>> v1;
    int sum=0;
    void pre(TreeNode* root,vector<int>&v,int key){
        if(!root) return;
        sum+=root->val;
        v.push_back(root->val);
        if(!root->left&&!root->right)
            if(sum==key) 
                v1.push_back(v);
        pre(root->left,v,key);
        pre(root->right,v,key);
        v.pop_back();
        sum-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        pre(root,v,targetSum);
        return v1;
    }
};