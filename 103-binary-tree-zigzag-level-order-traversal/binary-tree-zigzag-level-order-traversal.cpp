class Solution {
public:

    void bfs(TreeNode* root, vector<int> &v, vector<vector<int>> &ans, int y) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
   
    while (!q.empty()) {
        int levelSize = q.size();
        v.clear();  // Clear v at the beginning of each level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left != NULL) {
               q.push(temp->left);
            }
            if (temp->right != NULL) {
               q.push(temp->right);
            }
        }
        if (y % 2 != 0) {
            reverse(v.begin(), v.end());
        }
        y++;
        ans.push_back(v);
    }
}


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
         vector<int> v;
         int y=0;
         
        bfs(root,v,ans,y);



         return ans;
    }
};