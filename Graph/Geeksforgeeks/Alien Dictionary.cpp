/*
    Problem Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
*/

class Solution{
    private:
        vector<int> topologicalSort(int K, vector<int> adj[]){
            vector<int> indegree(K, 0);
            for(int i=0; i<K; i++){
                for(auto it: adj[i]){
                    indegree[it]++;
                }
            }
            
            queue<int> q;
            for(int i=0; i<K; i++){
                if(indegree[i] == 0)    q.push(i);
            }
            
            vector<int> topo;
            while(!q.empty()){
                int node= q.front();
                q.pop();
                
                topo.push_back(node);
                for(auto adjNode: adj[node]){
                    indegree[adjNode]--;
                    if(indegree[adjNode] == 0)  q.push(adjNode);
                }
            }
            
            return topo;
        }
    public:
    string findOrder(string dict[], int N, int K) {
        // using topological sort
        vector<int> adj[K];
        for(int i=0; i<N-1; i++){
            string s1= dict[i];
            string s2= dict[i+1];
            int len= min(s1.size(), s2.size());
            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); 
                    break;  
                }
            }
        }
        vector<int> topo= topologicalSort(K, adj);
        string ans="";
        for(auto it: topo){
            ans+= char(it + 'a');     // converting back from numbers 
        }
        
        return ans;
    }
};