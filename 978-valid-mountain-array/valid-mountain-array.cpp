class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size()-1;
       if(arr.size()<3)return false;
int y=0;
       for(int i=1;i<arr.size()-1;i++){
      if(arr[i]>arr[i-1] && arr[i]>arr[i+1])y++;
      if(arr[i]==arr[i-1] || arr[i]==arr[i+1])return false;
       } 
if(y==1 && arr[0]<arr[1] && arr[n]<arr[n-1])return true;

return false;
    }
};