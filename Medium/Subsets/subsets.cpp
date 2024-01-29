//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void sub(int i,vector<int>& A,vector<int>& C,vector<vector<int>>&B){
        
        if(A.size()==i){
         B.push_back(C);
        
            return;
        }
        C.push_back(A[i]);
        
        sub(i+1,A,C,B);
        C.pop_back();
        sub(i+1,A,C,B);
        
        
    } 
    vector<vector<int> > subsets(vector<int>& A)
    {   vector<int>  C;
        vector<vector<int> > B;
        
        sub(0,A,C,B);
        sort(B.begin(),B.end());
        return B;
       
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