//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
      int r=0,z=0,o=0,t=0,mn=INT_MAX;
      
      
      for(int i=0;i<S.length();i++){
          if(S[i]=='0')z++;
          else if(S[i]=='1')o++;
          else{
              t++;
          }
          while(z>=1 && o>=1 && t>=1){
              int l=i-r+1;
              mn=min(mn,l);
              if(S[r]=='0')z--;
          else if(S[r]=='1')o--;
          else{
              t--;
          }
          r++;
          }
      }
      if(mn==INT_MAX)return -1;
      return mn;
      
             
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends