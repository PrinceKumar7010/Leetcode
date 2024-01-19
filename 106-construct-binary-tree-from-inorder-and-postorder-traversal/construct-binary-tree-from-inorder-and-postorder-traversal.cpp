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

     int search(vector<int>& inorder,int start,int end ,int value)
     {
         for(int i=start;i<=end;i++)
         {
             if(inorder[i]==value)
             {
                 return i;
             }
         }
         return -1;
     }

    
    
    TreeNode* solve(vector<int>&inorder,vector<int>& postorder,int start,int end,int & index)
    {
       
        if(start>end)
        {
            return NULL;
        }
        int current=postorder[index];
        index--;
        TreeNode * root=new TreeNode(current);
        if(start==end)
        {
            return root;
        }

        int position=search(inorder,start,end,current);
        root->right=solve(inorder,postorder,position+1,end,index);
        root->left=solve(inorder,postorder,start,position-1,index);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=inorder.size()-1;
        return solve(inorder,postorder,0,inorder.size()-1,index);
        
    }
};