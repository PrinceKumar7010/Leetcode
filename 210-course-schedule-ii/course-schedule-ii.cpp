class Solution {
public:
    bool all_parent_visited(int node, vector<vector<int>> parent, vector<int> visited){
        for(auto p : parent[node]){
            if(!visited[p]) return false;
        }
        return true;
    }
    void BFS(vector<int> &visited, vector<int> &order, vector<vector<int>> directed,  vector<int> startNode
    , vector<vector<int>> parent){
        queue<int> q;

        for(int i = 0; i < startNode.size(); i++){
            if(startNode[i] == 0){
                q.push(i);
                visited[i] = 1; 
            }
        }

        while(!q.empty()){
            int node = q.front();
            order.push_back(node);
            q.pop();
            for(auto neigh : directed[node]){
                if(!visited[neigh] and all_parent_visited(neigh, parent, visited)){
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        if(!prerequisites.size()){
            for(int i = 0; i < numCourses; i++){
                order.push_back(i);
            }
            return order;
        }

        vector<int> startNode(numCourses);
        vector<vector<int>> parent(numCourses);

        vector<vector<int>> directed(numCourses);
        for(int i = 0; i <  prerequisites.size(); i++){
            directed[prerequisites[i][1]].push_back(prerequisites[i][0]);
            startNode[prerequisites[i][0]] = 1;
            parent[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> visited(numCourses, 0);
        BFS(visited, order, directed, startNode, parent);

        if(order.size() != numCourses){
            vector<int> ans;
            return ans;
        }

        return order;
    }
};