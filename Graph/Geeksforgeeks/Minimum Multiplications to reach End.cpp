/*
    Problem Link: https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> dist(1e5, 1e9); // size is 10^5-1
        q.push({start, 0});
        dist[start]= 0;
        int mod= 1e5;
        while(!q.empty()){
            int node= q.front().first;
            int steps= q.front().second;
            q.pop();
            
            for(auto it: arr){
                int num= (it * node) % mod;     // finding modulo if exceeds the mod
                if(steps + 1 < dist[num]){
                    dist[num]= steps + 1;
                    if(num == end)  return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};