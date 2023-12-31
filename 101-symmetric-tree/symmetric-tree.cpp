class Solution {
public:
   
   bool tree(TreeNode* p,TreeNode* q){
         if(p==NULL&&q!=NULL)return false;
         if(p!=NULL&&q==NULL)return false;
         if(p==NULL && q==NULL)return true; 


          if(p->val!=q->val)return false;
          if(p and q and p->val==q->val){
          if((tree(p->left,q->right))&&(tree(q->left,p->right))){
return true;
          }}
           return false;
       
   }

    
    bool isSymmetric(TreeNode* root) {

         if(tree(root->left,root->right))return true;
         return false;
    }
};