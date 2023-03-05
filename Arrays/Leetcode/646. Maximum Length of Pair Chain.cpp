/*
    Problem Link: https://leetcode.com/problems/maximum-length-of-pair-chain/
    
    Time: 68 ms (Beats 82.46%), Space: 22.5 MB (Beats 91.42%)
*/

class Solution {
    static bool sortFinishTime(vector<int>& s1, vector<int>& s2){
        return s1[1] < s2[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), sortFinishTime);

        int len=1, n= pairs.size();
        for(int i=0, j=1; j<n; j++){
            if(pairs[i][1] < pairs[j][0]){
                len++;
                i= j;
            }
        }
        return len;
    }
};