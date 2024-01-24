class Solution {
public:
 
      void sub(vector<int>& nums,int i, vector<int> &v1,vector<vector<int>> &ans){
           
      if(i==nums.size()){
          ans.push_back(v1);
          return ;
      }

      v1.push_back(nums[i]);
      sub(nums,i+1,v1,ans);
      v1.pop_back();
      sub(nums,i+1,v1,ans);
     


    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> v;
      sub(nums,0,v,ans);
      sort(ans.begin(),ans.end());
      return ans;
       }
      
    
};