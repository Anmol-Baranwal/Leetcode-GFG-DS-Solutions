// -----Approach 1: Space Optimisation ------------------------------------------------------------

// you can use memoization and tabulation method too but space optimisation is the most efficient
/*
    Problem Link: https://leetcode.com/problems/n-th-tribonacci-number/
    
    Time: 0 ms (Beats 100%), Space: 5.9 MB (Beats 77.86%)
*/

class Solution {
public:
    int tribonacci(int n) {
        int prev3= 0, prev2= 1, prev1= 1;
        int curr;

        if(n==0)    return 0;
        if(n==1 || n==2)    return 1;
        for(int i=3; i<=n; i++){
            curr= prev3 + prev2 + prev1;
            prev3= prev2;
            prev2= prev1;
            prev1= curr;
        }
        return prev1;
    }
};
