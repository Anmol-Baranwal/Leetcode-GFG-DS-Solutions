/*
    Problem Link: https://leetcode.com/problems/island-perimeter/
    
    Time: 212 ms (Beats 49.7%), Space: 96.2 mb (Beats 60.6%)
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        int ans=0;
        int side=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans++;

                    if(i != 0 && grid[i-1][j] == 1) side++;
                    if(j != 0 && grid[i][j-1] == 1) side++;
                }
            }
        }
        return ans*4 - side*2;
    }
};