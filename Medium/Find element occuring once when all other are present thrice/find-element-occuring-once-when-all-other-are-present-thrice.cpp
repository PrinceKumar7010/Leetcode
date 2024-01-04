//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
         sort(arr,arr+N);
        for(int i=0;i<N;i++)
        {
            if((i==0) && (arr[i]!=arr[i+1]))
            {
                return arr[i];
            }
            else if((i==N-1) && (arr[i] != arr[N-2]))
            {
                return arr[i];
            }
            else if((arr[i] != arr[i-1]) && (arr[i] != arr[i+1]))
            {
                return arr[i];
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends