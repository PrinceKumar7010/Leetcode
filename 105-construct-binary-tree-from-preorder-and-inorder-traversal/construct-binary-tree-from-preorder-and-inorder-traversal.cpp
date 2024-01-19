class Solution {
public:
  
   int search(vector<int>& inorder,int start,int end, int current)
   {
       for(int i=start;i<=end;i++)
       {
           if(inorder[i]==current)
           {
               return i;
           }
       }
       return -1;
   }
 int index=0;
   TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int start,int end)
   {
       
       if(start>end)
       {
           return NULL;
       }

       int current=preorder[index];
       index++;
       TreeNode* root=new TreeNode(current);
       if(start==end)
       {
           return root;
       }

       int position=search(inorder,start,end,current);
       root->left= solve(preorder,inorder,start,position-1);
       root->right=solve(preorder,inorder,position+1,end);
       return root;

   }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return solve(preorder,inorder,0,preorder.size()-1);
        
    }
};