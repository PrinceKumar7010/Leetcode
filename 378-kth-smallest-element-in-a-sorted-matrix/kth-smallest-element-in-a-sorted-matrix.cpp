class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
      vector<int>v;int n=m.size();
      for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          v.push_back(m[i][j]);
      }   
      }
      sort(v.begin(),v.end());
      return v[k-1];

    }
};