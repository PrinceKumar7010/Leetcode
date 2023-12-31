//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
  bool solve(vector<int>& arr,int sum,int n){
        // vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
        
        vector<bool> prev(sum+1,0);
        vector<bool> curr(sum+1,0);
        
        curr[0]=prev[0]=true;
        prev[arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i]>j){
                    curr[j]=prev[j];
                }
                else if(arr[i]<=j){
                    curr[j]=prev[j] || prev[j-arr[i]];
                }
            }
            prev=curr;
        }
        return prev[sum];
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        return solve(arr,sum,n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends