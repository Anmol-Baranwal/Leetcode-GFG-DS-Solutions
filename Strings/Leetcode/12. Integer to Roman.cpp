/*
    Problem Link: https://leetcode.com/problems/integer-to-roman/
    
    Time: 11 ms (Beats 57.74%), Space: 6.1 MB MB (Beats 50.82%)
*/

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        string symbol[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int valCalc[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};     
        // storing backwards for ease in calculation (we can use the values directly)
        int valSize= 6;
        for(int i=0; num > 0; i++){
            while(num >= valCalc[i]){
                num -= valCalc[i];
                ans += symbol[i];
            }   
        }

        return ans;
    }
};