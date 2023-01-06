/*
    Problem Link: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
*/

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here (Very Tough Problem to implement)
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        vector<string> usedForLevel;
        usedForLevel.push_back(beginWord);
        int level= 0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec= q.front();
            q.pop();
            
            if(vec.size() > level){
                level++;
                for(auto it: usedForLevel){
                    st.erase(it);
                }
                usedForLevel.clear();
            }
            
            string word= vec.back();
            
            if(word == endWord){
                if( (ans.size() == 0) || (ans[0].size() == vec.size()) ){
                    ans.push_back(vec);    
                }
            }
            
            for(int i=0; i<word.size(); i++){
                char inititalCh= word[i];
                for(char c='a'; c<='z'; c++){
                    word[i]= c;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited
                        usedForLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]= inititalCh;
            }
            
        } // queue becomes empty
        return ans;
    }
};