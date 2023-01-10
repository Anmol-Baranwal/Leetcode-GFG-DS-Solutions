/*
    Problem Link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1 
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n= matrix.size();
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(i == j)  matrix[i][j]= 0; 
	            if(matrix[i][j]==-1)    matrix[i][j]= 1e9;
	        }
	    }
	    
	    for(int k=0; k<n; k++){
	       for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j]= min((matrix[i][k] + matrix[k][j]), matrix[i][j]);  
	            }
	        } 
	    }
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==1e9)    matrix[i][j]= -1;  // converting back
	        }
	    }
	    
	    // we can also use auto:
	    // for(auto &mat: matrix){
	    //     for(auto &it: mat){ 
	    //         if(it == 1e9)    it= -1;
	    //     }
	    // }
	    
	    // for -ve cycle we can check matrix[i][i] < 0
	}
};
