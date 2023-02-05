// -----Approach 1: ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/ugly-number/
    
    Time: 0 ms (Beats 100%), Space: 6 MB (Beats 55.61%)
*/

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        while(n>1){
            if (n % 2 == 0) n /=2;
            else if (n % 3 == 0) n /=3;
            else if (n % 5 == 0) n /=5;
            else break;
        }

        return n == 1;
    }
};

// -----Approach 2: ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/ugly-number/
    
    Time: 0 ms (Beats 100%), Space: 6 MB (Beats 6.19%%)
*/

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        for (int i=2; i<6 && n; i++)
            while ( n%i == 0 )
                n /= i;

        return n == 1;
    }
};
