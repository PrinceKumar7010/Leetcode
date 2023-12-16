//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
      unsigned long long solve(long long int n,vector<long long int> &dp){
             int mod = 1000000007L;
            if(n==0 || n==1)return 1;
            if(n<0) return 0;
            if (dp[n]!=-1)return dp[n];
            return dp[n]=(solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp))%mod;
        }

       
    
    
    
    
  unsigned long long int countWays(int n)
{
    vector<long long int> dp(n+1, -1);
    return solve(static_cast<long long int>(n), dp);
}
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends