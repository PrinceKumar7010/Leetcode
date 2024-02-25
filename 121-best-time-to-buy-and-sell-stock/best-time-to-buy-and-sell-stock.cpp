class Solution {
public:
    int maxProfit(vector<int>& arr) {
       int mini=arr[0];
       int cur=0,mx=0;
       for(int i=0;i<arr.size();i++){
         cur=arr[i]-mini;
         mx=max(mx,cur);
         mini=min(mini,arr[i]);

       } 
       return mx;
    }
};