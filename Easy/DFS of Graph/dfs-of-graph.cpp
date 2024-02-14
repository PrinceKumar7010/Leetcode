//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    
    void dfs(int source,vector<bool> &vis, vector<int> &v,vector<int> adj[]){
        
       
        vis[source]=true;
     v.push_back(source);
        for(int i  : adj[source]){
            if(!vis[i])dfs(i,vis,v,adj);
            
        }
        
        
    }
    
    
     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
          vector<int> v;
        vector<bool> vis(V,false);
        dfs(0,vis,v,adj);
        
        return v;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends