/*
    Problem Link: https://leetcode.com/problems/happy-number/
    
    Time: 4 ms (Beats 38.16%), Space: 5.9 MB (Beats 91.3%)
*/

class Solution {
private:
    int next(int n)
    {
        int sum= 0;
        
        while(n != 0){
            sum+= pow(n % 10,2);
            n= n/10;
        }
        
        return sum;
    }
public:
    bool isHappy(int n) {
        int s= next(n);
        int f= next(next(n));
        
        while(s != f)
        {
            s= next(s);
            f= next(next(f));
        }
        
        return f == 1 ;
    }
};