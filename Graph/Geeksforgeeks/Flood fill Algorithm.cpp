/*
    Problem Link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int newColor, int iColor){
        int n= image.size();
        int m= image[0].size();
        ans[row][col]=newColor;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow= row + delrow[i];
            int ncol= col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == iColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, image, ans, newColor, iColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int inColor= image[sr][sc];
        vector<vector<int>>& ans= image;
        dfs(sr, sc, image, ans, newColor, inColor);
        
        return ans;
    }
};