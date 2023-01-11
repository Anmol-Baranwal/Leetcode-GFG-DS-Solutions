/*
    Problem Link: https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/0
*/

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // using floyd warshall algo (we can also use dijikstra algo as well)
        vector<vector<int>> dist(n, vector<int>(n, 1e9));   // n*n
        for(auto it: edges){
            dist[it[0]][it[1]]= it[2];
            dist[it[1]][it[0]]= it[2];
        }
        
        for(int i=0; i<n; i++)  dist[i][i]= 0;
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9){
                        dist[i][j]= min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int cntCity= n;
        int currCity= -1;
        for(int city=0; city<n; city++){
            int cnt=0;
            for(int adjCity=0; adjCity<n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold)   cnt++;
            }
            
            if(cnt <= cntCity){
                cntCity= cnt;
                currCity= city;
            }
        }
        
        return currCity;
    }
};

// ---------------------------------------------------
// we can also initialize dist using this
for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        if(i==j)
        dist[i][j] = 0;
    }
}

// (m would be used in this case)
for(int i=0;i<m;++i){
    int u = edges[i][0];
    int v = edges[i][1];
    int cost = edges[i][2];
    
    dist[u][v] = cost;
    dist[v][u] = cost;
}