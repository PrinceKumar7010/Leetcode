//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
       int i=0;
       int j=n-1;
       vector<int> v;
       bool t=true;
       bool h=true;
       while(i<n && j>=0){
           if(arr[i]==x && t){
               v.push_back(i);
               t=false;
                
           }
           else{
               i++;
           }
            if(arr[j]==x && h){
               v.push_back(j);
                 h=false;
                
                
           }
           else{
               j--;
           }
              
       }
       if(v.size()<2){
           v.push_back(-1);
       v.push_back(-1);
           
       }
       sort(v.begin(),v.end());
       return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends