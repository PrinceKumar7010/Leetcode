//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    
    public:
    
    void sub (vector<int> &A,int i,vector<int> &B,vector<vector<int> > &ans){
        
        if(i==A.size()){
            ans.push_back(B);
            return ;
        }
        B.push_back(A[i]);
        sub(A,i+1,B,ans);
        
        B.pop_back();
        sub(A,i+1,B,ans);
        
    }
    
    vector<vector<int> > subsets(vector<int>& A)
    {   vector<vector<int> > ans;
        vector<int> B;
        sub(A,0,B,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends