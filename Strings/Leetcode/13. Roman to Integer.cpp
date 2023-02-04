// -----Approach 1: most efficient ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/roman-to-integer/
    
    Time: 12 ms (Beats 63.64%), Space: 7.8 MB (Beats 46.46%)
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        int ans=mpp[s.back()];  // to access last char .back() is used

        for(int i= s.size()-2; i>=0; --i){   // this will prevent from reaching out of bounds
            if( mpp[s[i]] < mpp[s[i+1]] )    // smaller no before higher is:  IV (4), IX (9)
                ans-= mpp[s[i]];
            else
                ans+= mpp[s[i]];
        }

        return ans;
    }
};


// -----Approach 2: using concept of smaller number generation in roman ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/roman-to-integer/
    
    Time: 19 ms (Beats 43.1%), Space: 9 MB (Beats 10.19%)
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        int ans=0;

        for(int i=0; i<s.size(); i++){
            if( mpp[s[i]] < mpp[s[i+1]] )    // smaller no before higher is:  IV (4), IX (9)
                ans-= mpp[s[i]];
            else
                ans+= mpp[s[i]];
        }

        return ans;
    }
};


// -----Approach 3: using substr ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/roman-to-integer/
    
    Time: 43 ms (Beats 5.98%), Space: 12.9 MB MB (Beats 10.19%)
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mpp= {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};;

        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(mpp.find(s.substr(i, 2)) == mpp.end()){    // this means we didnt found 2 letter values
                ans+= mpp[s.substr(i, 1)];  
            }
            else{
                ans+= mpp[s.substr(i++, 2)];  
                // this must be done as double letter values are present
            }
        }    
        return ans;
    }
};