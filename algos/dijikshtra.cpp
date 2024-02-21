#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    vector<pair<int,int>>adj[n];
    for(auto edge: edges){
          adj[edge[0]].push_back({edge[1],edge[2]});
          adj[edge[1]].push_back({edge[0],edge[2]});
    }

    vector<int> dis(n);
    for(int i=0;i<n;i++)dis[i]=1e9;
    dis[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int curnode = q.front();
        q.pop();
            // int curdis = q.front().second;
          for (auto aj : adj[curnode]) {
            if (dis[curnode] + aj.second < dis[aj.first]) {
              dis[aj.first] = dis[curnode] + aj.second;
              q.push(aj.first);
            }
          }
        
    }
    for(int i=0;i<n;i++)
    if(dis[i]==1e9)dis[i]=-1;
    return dis;

}
int main() {
   vector<vector<int>>edges={{0,1,2},{1,4,1},{4,2,10},{4,3,20},{2,3,1}};
   vector<int>ans=shortestPath(5,edges,1);
   for ( int i =0; i< ans.size();i++ ){
    cout<< "dis of node " << i << " from node 1 is " << ans[i] << endl;
   }

  
}