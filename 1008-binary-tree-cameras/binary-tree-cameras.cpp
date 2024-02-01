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
    int res = 0;
public:
    int minCameraCover(TreeNode* root) {
      pair<bool, bool> rootStatus = haveCamera(root);
      if (rootStatus.second == false) res++;
      return res;
    }
    pair<bool, bool> haveCamera(TreeNode* root) { // return pair<a, b>, a -> have camera, b -> have been covered by camera
      if (root == NULL) return {false, true};

      pair<bool, bool> left = haveCamera(root->left);
      pair<bool, bool> right = haveCamera(root->right);

      if (left.second == false || right.second == false) {
        res++;
        return {true, true};
      }
      if (left.first == true || right.first == true) {
        return {false, true};
      }


      return {false, false};
    }
};