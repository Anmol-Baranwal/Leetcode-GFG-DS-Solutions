/*
    Problem Link: https://leetcode.com/problems/ugly-number-ii/
    
    Time: 0 ms (Beats 100%), Space: 6.2 MB (Beats 91.27%)
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> vec;
        long a, b, c, m= INT_MAX;
        if (vec.empty()){
            for (a=1; a<=m; a*=2){
                for (b=a; b<=m; b*=3){
                    for (c=b; c<=m; c*=5){
                        vec.push_back(c);
                    }
                }
            }           
            sort(vec.begin(), vec.end());
        }
        
        return vec[n-1];
    }
};
