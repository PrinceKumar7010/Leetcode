//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knap(int weight[],int value[],int maxWeight,int i,vector<vector<int>>&dp ){
        if(i<0 || maxWeight==0)return  0;
        if(dp[i][maxWeight]!=-1) return dp[i][maxWeight];
        int take=0;
        if(weight[i]<=maxWeight)take=value[i]+knap(weight,value,maxWeight-weight[i],i-1,dp);
        int ntake=knap(weight,value,maxWeight,i-1,dp);
        return dp[i][maxWeight]=max(take,ntake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
        return knap(wt,val,W,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends