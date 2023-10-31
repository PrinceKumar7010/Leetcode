//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    string caseSort(string str, int n)
    {
        string ans="";
     
        vector<int> v;
        vector<char> cp;
        vector<char> sl;
        for(int i=0;i<str.length();i++){
            if(str[i]>=65 && str[i]<=90){
                v.push_back(1);
                cp.push_back(str[i]);
            }
            else{
                v.push_back(0);
                 sl.push_back(str[i]);
                
            }
        }
        sort(sl.begin(),sl.end());
        sort(cp.begin(),cp.end());
        int k=0;
        int h=0;
        for(int i=0;i<str.length();i++){
            if(v[i]==0){
                ans+=sl[k];
                k++;
            }
            else{
                 ans+=cp[h];
                 h++;
            }
            
        }
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends