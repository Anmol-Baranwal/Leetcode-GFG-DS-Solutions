/*
    Problem Link: https://leetcode.com/problems/course-schedule-ii
    
    Time: 28 ms (Beats 70.42%), Space: 13.7 MB (Beats 72.74%)
*/

class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto adjNode: adj[i]){
                indegree[adjNode]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)    
            if(indegree[i]==0)  q.push(i);

        vector<int> ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0)    q.push(adjNode);    
            }
        }
        if(ans.size()==V)   return ans;
        else    return {};

    }
};
