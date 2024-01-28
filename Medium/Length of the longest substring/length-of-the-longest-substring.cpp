//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        unordered_map <int,int> mp;
        int len=0,j=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
              len=max(i-j+1,len); 
              mp[s[i]]++;
            }
            else{ 
                mp.erase(s[j++]);
                i--;
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends