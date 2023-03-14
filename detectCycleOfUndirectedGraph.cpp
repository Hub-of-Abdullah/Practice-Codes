/*
Time Complexity O(V+E);
Space Complexity O(V);
Given a undirected graph....
1. Detect Cycle of graph and print the nodes of cycle.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> graph;
vector<bool> vis;
vector< int >path;
vector< int >theCycle;
bool cycle;

void dfs(int root, int parrentOfRoot){
    if(cycle) return;
    vis[root] = true;
    theCycle.push_back(root);

    for(auto child : graph[root]){
        if(child != parrentOfRoot){
            if(vis[child]) cycle  = true;
            else  dfs(child, root);
        }
    }
    if(!cycle) theCycle.pop_back();
}


bool isCycle(int nodes){
    cycle  = false;
    for(int i =0; i<nodes; i++){
        if(cycle) return true;
        if(!vis[i]) dfs(i,-1);
    }
    return false;
}
int main(){
    int t, n, e, x, y;cin>>t;
    while(t--){
        cin>>n>>e;
        graph.clear();
        vis.clear();
        graph.resize(n);
        vis.assign(n, false);
        path.assign(n, false);
        for(int i =0; i<e; i++){
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
       if(isCycle(n)){
        cout<<"Yes the Cycle is : ";
        for(auto x : theCycle) cout<<x<<" ";
        cout<<endl;
       }
       else{
        cout<<"NO Cycle"<<endl;
       }
    }
return 0;
 }
/*
2
6 7
0 1
0 2
1 5
2 3
3 4
3 5
4 5

6 5
0 1
0 2
1 5
2 3
3 4


*/
