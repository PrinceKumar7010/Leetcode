//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n%2 != 0)
            return 0;
            
        map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            int curr = nums[i]%k;
            int need = (k-curr)%k;
            
            if(mp.find(need)!=mp.end())
            {
                mp[need]--;
                
                if(mp[need]==0)
                    mp.erase(need);
            }
            else
            {
                mp[curr]++;
            }
        }
        
        if(mp.size()==0)
            return 1;
        return 0;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends