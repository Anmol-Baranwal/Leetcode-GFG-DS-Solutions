// -----Approach 1: ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-string-chain/
    
    Time: 2405 ms (Beats 10.88%), Space: 644.8 MB (Beats 5.6%)
*/

// I have not done this with other efficient approach, due to work burden. (I will likely do it in upcoming weeks)

class Solution {
private:
    bool check(string s1, string s2){
        if(s1.size() != s2.size()+1)    return false;
        int first= 0, second= 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else    first++;
        }
        if(first == s1.size() && second == s2.size())   return true;
        return false;
    }
    static bool comp(string s1, string s2){
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n= words.size();

        sort(words.begin(), words.end(), comp);   // this is under stl c++, sorting using custom rule
        int mx= 1;
        vector<int> dp(n, 1);

        for(int idx=0; idx<n; idx++){
            for(int prevIdx=0; prevIdx<idx; prevIdx++){
                if( check(words[idx], words[prevIdx]) && dp[idx] < dp[prevIdx] + 1){
                    dp[idx]= dp[prevIdx] + 1;
                }
            }
            if(dp[idx] > mx)    mx= dp[idx];
        }

        return mx;
    }
};