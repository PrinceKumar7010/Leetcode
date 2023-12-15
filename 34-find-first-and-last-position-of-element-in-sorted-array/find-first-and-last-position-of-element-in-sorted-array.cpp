class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
      int i=0,j=nums.size()-1;
      vector<int> v;
      int s=0,f=0;

      while(i<=j){
      if(nums[i]==t){
        v.push_back(i);
        s++;
        break;
      }
      i++;
      }
      i=0,j=nums.size()-1;
      if(s==0) v.push_back(-1);

       while(i<=j){
      if(nums[j]==t){
        v.push_back(j);
        f++;
        break;
      }
      j--;
      
      }
      if(f==0) v.push_back(-1);

return v;
     }

};