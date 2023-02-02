/*
    Problem Link: https://leetcode.com/problems/powx-n/
    
    Time: 5 ms (Beats 12.85%), Space: 5.9 MB (Beats 72.47%)
*/

class Solution {
public:
    double myPow(double x, int n) {
        double ans= 1.0;
        long temp= n;
        
        if(n<0) temp*= -1;
            
        while(temp>0){
            if(temp%2==0){
                x*= x;
                temp/= 2;
            }else{
                ans*= x;
                temp--;
            }    
        } 
        if(n<0) ans= (double) 1.0/ (double) ans;
        return ans;
    }
};