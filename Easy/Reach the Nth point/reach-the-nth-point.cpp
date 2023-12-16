//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	
	   long long int s(int n,vector<long long int> &dp){
	        int mod = 1e9 + 7;
	       if(n==0||n==1)return 1;
	       if(n<0) return 0;
	       if(dp[n]!=-1)return dp[n];
	       return dp[n]=(s(n-1,dp)+s(n-2,dp))%mod;
	   }
		int nthPoint(int n){
		    vector<long long int> dp(n+1,-1);
		    return s(n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends