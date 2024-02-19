//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

 void sub(vector<int> &v,int n,int i,int sum,vector<int> arr){
     
     if(i==n){
         v.push_back(sum);
         return ;
     }
     
     sub(v,n,i+1,sum+arr[i],arr);
   
     sub(v,n,i+1,sum,arr);
     
     
 }

    
    vector<int> subsetSums(vector<int> arr, int n)
    {
         vector<int> v;
         sub(v,n,0,0,arr);
       return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends