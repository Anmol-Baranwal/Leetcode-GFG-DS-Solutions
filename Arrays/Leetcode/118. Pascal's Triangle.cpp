// -----Approach 1 ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/pascals-triangle/
    
    Time: 6 ms (Beats 6.52%), Space: 6.4 MB (Beats 83.65%)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        for(int i=0; i<numRows; i++){
            vector<int> ans(i+1, 1); // we are making corresponding elements for the pascal triangle
            
            for(int j=1; j<i; j++){  // we are using the row value to actually jump to the initial step
                ans[j]= res[i-1][j-1] + res[i-1][j];  // we are using the above two values to get this value
                // res.push_back(ans);
            }
            res.push_back(ans);
        }
        return res;
        
    }
};

// -----Approach 2 ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/pascals-triangle/
    
    Time: 4 ms (Beats 30.5%), Space: 6.6 MB (Beats 58.96%)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        for(int i=0; i<numRows; i++){
            // vector<int> ans(i+1, 1); // we are making corresponding elements for the pascal triangle
            res[i].resize(i + 1);
            
            res[i][0] = res[i][i] = 1;
            
            for(int j=1; j<i; j++){  // we are using the row value to actually jump to the initial step
                
                res[i][j]= res[i-1][j-1] + res[i-1][j];  // we are using the above two values to get this value

            }
            // res.push_back(ans);
        }
        return res;
        
    }
};