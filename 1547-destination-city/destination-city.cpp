#include <algorithm>
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
         vector<string> ans;
         string result;
         for(int i=0;i<paths.size();i++){
            ans.push_back(paths[i][0]);
         }
         for(int j=0;j<paths.size();j++){
if (find(ans.begin(), ans.end(), paths[j][1])  == ans.end()) {
                result=paths[j][1];
            }
         }
         return result;
    }
};