//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
   
   int mx = INT_MIN;
    int j = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;

        if (mp.size() == k) {
            mx = max(mx, i - j + 1);
        }
        while (mp.size() > k) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) {
                mp.erase(s[j]);
            }
            j++;
        }
    }
    if(mp.size()<k)return -1;
    return mx;
   
   
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends