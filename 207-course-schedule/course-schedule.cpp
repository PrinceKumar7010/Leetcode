class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegrees(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
            indegrees[it]++;
            }

        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegrees[i]==0){q.push(i);}
        }
        int count=0;
        while(q.empty()!=true)
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node])
            {
                indegrees[it]--;
                if(indegrees[it]==0){q.push(it);}
            }

        }
        if(count==numCourses){return true;}
        return false;
    }
};