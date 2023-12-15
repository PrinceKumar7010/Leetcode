//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
         long sum = 0;
    long maxSum = 0;

    // Calculate the sum of the first k elements
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    
    maxSum = sum; // Set maxSum to the sum of the first subarray of size k

    // Calculate the sum of remaining subarrays and update maxSum if necessary
    for (int i = k; i < n; i++) {
        sum = sum + arr[i] - arr[i - k]; // Update the sum by adding the next element and excluding the first element of the current subarray
        maxSum = std::max(maxSum, sum); // Update maxSum if the current sum is greater
    }
    
    return maxSum;
}
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends