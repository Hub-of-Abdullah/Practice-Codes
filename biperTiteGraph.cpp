/*
Can use DFS or BFS
Time Complexity - (V+E)
Space Complexity - (V)
5
8 10
1 3
1 2
1 5
2 4
2 6
3 7
5 6
5 7
6 8
4 8
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>graph[1000];
int col[1000];
bool vis[1000];


bool bfs(int root, int c){
    queue<int>Q;
    Q.push(root);
    vis[root] = true;
    col[root] = c;

    while(!Q.empty()){
        root = Q.front(); Q.pop();
        for(auto child : graph[root]){
            if(!vis[child]){
                col[child] = col[root]^1;
                vis[root] = true;
                Q.push(child);
            }
            if(col[root] == col[child])return false;
        }
    }
    return true;
}

int main(){
    int t,nodes, edges, x, y;cin>>t;
    while(t--){
        cin>>nodes>>edges;
        for(int i =0;i<1000; i++) vis[i] = false;
        for(int i =0;i<1000; i++) col[i] = 0;
        for(int i =0;i<1000; i++)graph[i].clear();

        for(int i = 0; i<edges; i++){
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bool ans = bfs(1, 0);
       // bool ans = dfs(1, 0);
        if(!ans)//If not bipartite then print -1
            cout << "-1" << endl;
        else{
            for(int i=1;i<=nodes; i++)
                if(col[i] == 0) cout << i << " ";//Print all nodes with color
            cout<<endl;
        }

    }

return 0;}
