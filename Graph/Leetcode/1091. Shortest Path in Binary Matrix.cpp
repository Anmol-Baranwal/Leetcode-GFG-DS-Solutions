// -----Approach 1: ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
    
    Time: 73 ms (Beats 72.60%), Space: 21.8 MB (Beats 50.94%)
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // we can directly put the source & destination pair 
        int n= grid.size();
        int m= grid[0].size();
        // pair<int,int> source ({0, 0});
        // pair<int,int> destination ({n-1, n-1});

        if(n==m && n==1){  //for the edge cases such as [[0]] && [[1]]
            if(grid[0][0]) return -1;
            return 1;
        }

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0]=1;
        q.push({{0, 0}, 1});
        int ans= INT_MAX;

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        while(!q.empty()){
            int dis= q.front().second;
            int row= q.front().first.first;
            int col= q.front().first.second;
            q.pop();

            // int dir[8][2] = {{1, 1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {-1, -1}, {0, -1}, {-1, 0}};
            int delrow[]= {-1,0,1,0,-1,-1,1,1};  
            int delcol[] ={0,-1,0,1,-1,1,1,-1};
            for(int i=0; i<8; i++){
                int nrow= row + delrow[i];
                int ncol= col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dist[nrow][ncol]>dis+1){
                    dist[nrow][ncol]=1;
                    if(nrow == n-1 && ncol == n-1) return min(ans, dis+1);
                    q.push({{nrow, ncol}, dis+1});
                }
            }
        }
        return -1;
    }
};

// -----Approach 2: ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
    
    Time: 83 ms (Beats 54.50%), Space: 21.9 MB (Beats 38.82%)
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // we can directly put the source & destination pair using source.first, destination.second, so on
        int n= grid.size();
        int m= grid[0].size();
        // pair<int,int> source ({0, 0});
        // pair<int,int> destination ({n-1, n-1});

        if(n==m && n==1){  //for the edge cases such as [[0]] && [[1]]
            if(grid[0][0]) return -1;
            return 1;
        }

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0]=1;
        q.push({{0, 0}, 1});
        int ans= INT_MAX;

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        while(!q.empty()){
            int dis= q.front().second;
            int row= q.front().first.first;
            int col= q.front().first.second;
            q.pop();

            // int dir[8][2] = {{1, 1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {-1, -1}, {0, -1}, {-1, 0}};
            int delrow[]= {-1,0,1,0,-1,-1,1,1};  
            int delcol[] ={0,-1,0,1,-1,1,1,-1};
            for(int i=0; i<8; i++){
                int nrow= row + delrow[i];
                int ncol= col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    if(nrow == n-1 && ncol == n-1) return min(ans, dis+1);
                    q.push({{nrow, ncol}, dis+1});
                }
            }
        }
        return -1;
    }
};

// -----Approach 3: (using solution tab) ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
    
    Time: 56 ms (Beats 97.15%), Space: 19.3 MB (Beats 80.78%)
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // edge case: start or end not accessible
        if (grid[0][0] || grid.back().back()) return -1;
        // support variables
        int res = 2, len = 1, maxX = grid[0].size() - 1, maxY = grid.size() - 1;
        queue<pair<int, int>> q;
        // edge case: single cell matrix
        if (!maxX && !maxY) return 1 - (grid[0][0] << 1);
        // adding the starting point
        q.push({0, 0});
        // marking start as visited
        grid[0][0] = -1;
        while (len) {
            while (len--) {
                // reading and popping the coordinates on the front of the queue
                auto [cx, cy] = q.front();
                q.pop();
                for (int x = max(0, cx - 1), lmtX = min(cx + 1, maxX); x <= lmtX; x++) {
                    for (int y = max(0, cy - 1), lmtY = min(cy + 1, maxY); y <= lmtY; y++) {
                        // check if we reached the target
                        if (x == maxX && y == maxY) return res;
                        // marking it as visited and adding it to the q if it was still a valid cell
                        if (!grid[y][x]) {
                            grid[y][x] = -1;
                            q.push({x, y});
                        }
                    }
                }
            }
            // preparing for the next loop
            res++;
            len = q.size();
        }
        return -1;
    }
};
