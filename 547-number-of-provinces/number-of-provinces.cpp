class Solution {
public:
    void dfs(int source, vector<bool>& vis, vector<int> id[]) {
        vis[source] = true;
        for (auto i : id[source]) {
            if (!vis[i])
                dfs(i, vis, id);
        }
    }
    int findCircleNum(vector<vector<int>>& id) {
        int c = 0;
        int n = id.size();

        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (id[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                c++;
            }
        }
        return c;
    }
};