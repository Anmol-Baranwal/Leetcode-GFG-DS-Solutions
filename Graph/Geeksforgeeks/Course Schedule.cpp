/*
    Problem Link: https://practice.geeksforgeeks.org/problems/course-schedule/1
*/

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> adj[n];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(n, 0);
        vector<int> ans;
        queue<int> q;
        
        for(int i=0; i<n; i++){
            for(auto adjNode: adj[i]){
                indegree[adjNode]++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)    q.push(i);
        }
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            ans.push_back(node);
            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        
        if(ans.size() == n) return ans;
        return {};
    }
};