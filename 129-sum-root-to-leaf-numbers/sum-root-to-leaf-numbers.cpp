class Solution {
public:
    vector<string>v;
    void pre(TreeNode* root,string &p){
      if(root==NULL)return ;
      string o=to_string(root->val);
      p=p+o;
      pre(root->left,p);
      pre(root->right,p);
  if(root->left==NULL && root->right==NULL)
{      
       v.push_back(p);
       }
       p.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        string a="";
        pre(root,a);
        int sum=0;
        for(auto i: v){
            int y=stoi(i);
            sum+=y;
        }
        
        return sum;
    }
};