/*
    Problem Link: https://leetcode.com/problems/set-matrix-zeroes/
    
    Time: 16 ms (Beats 72.28%), Space: 13.3 MB (Beats 65.22%)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col=1;
        int rowSize=matrix.size(), colSize=matrix[0].size(); // col is for 0th position
        for(int i=0 ; i<rowSize; i++){
            if(matrix[i][0]==0) col=0;    
            for(int j=1; j<colSize; j++)
                if(matrix[i][j]==0) matrix[0][j]=matrix[i][0]=0; 
        }
        // traversing from back
        for(int i=rowSize-1; i>=0; i--){
            for(int j=colSize-1; j>=1; j--)
                if(matrix[i][0]==0 or matrix[0][j]==0) matrix[i][j]=0;
            if(col==0)  matrix[i][0]=0;
        }
        
    }   
};
