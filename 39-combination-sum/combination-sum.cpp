class Solution {
public:


   void sub( vector<vector<int>> &ans,vector<int> &v,int n,int i,int tar,vector<int>can){

   if(i==n){
if(tar==0){
     ans.push_back(v);
   
   }
       return ;
   }
   
   
   
   if(can[i]<=tar){
       v.push_back(can[i]);
    sub(ans,v,n,i,tar-can[i],can);
    v.pop_back();
   }
   sub(ans,v,n,i+1,tar,can);
    


   }
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
         vector<vector<int>> ans;
         vector<int> v;
         int n=can.size();
sub(ans,v,n,0,tar,can);
return ans;
    }
};