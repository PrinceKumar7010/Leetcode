class Solution {
public:
    void rotate(vector<vector<int>>& a) {

    for(int i=0;i<a.size();i++) for(int j=0;j<i;j++) swap(a[j][i],a[i][j]);
    
 for(int i=0;i<a.size();i++) reverse(a[i].begin(),a[i].end());


    }
};