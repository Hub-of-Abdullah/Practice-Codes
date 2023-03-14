/*
Time Complexity O(V+E);
Space Complexity O(V);
Given a undirected graph....
1. Detect Cycle of graph and print the nodes of cycle.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>graph;
vector<bool> vis;
vector<bool> path;
vector< int >theCycle;

bool cycle;
void dfs(int root){
    if(cycle) return;
    vis[root] = true;
    path[root] = true;
    theCycle.push_back(root);

    for(auto child : graph[root]){
        if(path[child]) cycle = true;

        if(!vis[child]){
            dfs(child);
        }
    }
    if(!cycle) theCycle.pop_back();
    path[root] = false;
}

bool isCycle(int nodes){
    cycle = false;
    for(int i =0; i<nodes; i++){
        if(cycle) return true;
        if(!vis[i]) dfs(i);
    }
    return false;
}
int main(){
    int t,n,e,x,y;cin>>t;
    while(t--){
        cin>>n>>e;
        graph.clear();
        vis.clear();
        graph.resize(n);
        vis.assign(n, false);
        theCycle.clear();
        path.assign(n,false);

        for(int i=0; i<e; i++){
            cin>>x>>y;
            graph[x].push_back(y);
        }
        if(isCycle(n)){
            cout<<"Yes Cycle"<<endl;
            for(auto x : theCycle) cout<<x<<" ";
                cout<<endl;
        }
        else {
            cout<<"NO Cycle"<<endl;
        }

    }
return 0;
}
/*
Path variable use korar karon holo same node theke bar bar dfs call na kora.
2
7 10
0 1
1 2
1 3
2 6
2 4
3 5
4 5
4 1
5 1
5 6

5 6
0 1
0 2
1 3
1 4
2 3
3 4



*/
