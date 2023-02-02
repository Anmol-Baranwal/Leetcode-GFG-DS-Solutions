/*
    Problem Link: https://leetcode.com/problems/palindrome-number/
    
    Time: 3 ms (Beats 99.41%), Space: 5.8 MB (Beats 96.43%)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)   return false;
        int check = x;
        unsigned int rev=0;
        while(check != 0){
            rev = rev * 10 + check % 10;
            check /= 10;
        }
        
        return rev == x;

        // using vector

        // vector<int> ans;
        // if(x<0)  return false;
        // int temp=x;
        // while(temp){
        //     ans.push_back(temp%10);
        //     temp/=10;
        // }
        // int l=0, r=ans.size()-1;
        // while(l < r){
        //     if(ans[l] != ans[r]) return false;
        //     l++;
        //     r--;
        // }
        // return true;

    }
};