class Solution {
public:
     int tree_height(TreeNode* node){
        if(node==NULL)return 0;
        int left=tree_height(node->left);
        int right=tree_height(node->right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* node) {
        if(!node) return 0;
        int left=diameterOfBinaryTree(node->left);
        int right=diameterOfBinaryTree(node->right);
        int k=tree_height(node->left)+tree_height(node->right);
        return max(left,max(right,k));
    }
};