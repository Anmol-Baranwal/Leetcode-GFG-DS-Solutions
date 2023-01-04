/*
    Problem Link: https://leetcode.com/problems/flood-fill/
    
    Time: 11 ms (Beats 77.94%), Space: 14 MB (Beats 49.78%)
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int inColor, int color){
        int n= image.size();
        int m= image[0].size();
        ans[row][col]= color;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow= row + dr[i];
            int ncol= col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inColor && ans[nrow][ncol]!=color){
                dfs(nrow, ncol, ans, image, inColor, color);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor= image[sr][sc];
        vector<vector<int>> ans= image;
        dfs(sr, sc, ans, image, initialColor, color);

        return ans;
    }
};