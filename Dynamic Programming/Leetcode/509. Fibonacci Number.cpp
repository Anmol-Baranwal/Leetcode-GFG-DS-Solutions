// -----Approach 1: ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/fibonacci-number/
    
    Time: 0 ms (Beats 100%), Space: 5.8 MB (Beats 93.76%)
*/

class Solution {
public:
    int fib(int n) {
        if(n<=1)    return n;
        int prev2= 0;
        int prev= 1;
        int curr;
        for(int i=2; i<=n; i++){
            curr= prev + prev2;
            prev2= prev;
            prev= curr;
        }
        return curr;
    }
};

// -----Approach 2: ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/fibonacci-number/
    
    Time: 3 ms (Beats 69.77%), Space: 6.1 MB (Beats 21.41%)
*/

class Solution {
public:
    int fib(int n) {
        if(n==0)    return 0;
        int prev2= 0;
        int prev= 1;
        for(int i=2; i<=n; i++){
            int curr= prev + prev2;
            prev2= prev;
            prev= curr;
        }
        return prev;
    }
};
