//https://www.hackerearth.com/problem/algorithm/question-7-4/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int x,y,l;
};
int n, m,grid[100][100];
bool visited[100][100];
queue< node > Q;

bool isValid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}
bool left(int x, int y){
    return (grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 6 || grid[x][y] == 7);
}
bool right(int x, int y){
    return (grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 4 || grid[x][y] == 5);
}
bool up(int x, int y){
    return (grid[x][y] == 1 || grid[x][y] == 2 || grid[x][y] == 4 || grid[x][y] == 7);
}
bool down(int x, int y){
    return (grid[x][y] == 1 || grid[x][y] == 2 || grid[x][y] == 5 || grid[x][y] == 6);
}

int bfs(int x, int y, int lvl){
    int ans = 0;
    Q.push({x,y,lvl});
    visited[x][y] = true;

    node tmpNode1, tmpNode2;
    while(!Q.empty()){
        tmpNode1 = Q.front();
        Q.pop();
        x = tmpNode1.x;
        y = tmpNode1.y;
        lvl = tmpNode1.l;
        if(lvl==0) continue;

        ans++;

        if(isValid(x, y-1) && left(x,y) && right(x,y-1) && !visited[x][y-1]){
            Q.push({x,y-1,lvl-1});
            visited[x][y-1] = true;
        }
        if(isValid(x, y+1) && right(x,y) && left(x,y+1)&& !visited[x][y+1]){
            Q.push({x,y+1,lvl-1});
            visited[x][y+1] = true;
        }
        if(isValid(x-1, y) && up(x,y) && down(x-1,y) && !visited[x-1][y]){
            Q.push({x-1,y,lvl-1});
            visited[x-1][y] = true;
        }
        if(isValid(x+1, y) && down(x,y) && up(x+1,y) && !visited[x+1][y]){
            Q.push({x+1,y,lvl-1});
            visited[x+1][y] = true;
        }
    }
    return ans;
}
int main(){
    int t,sx,sy,lvl;cin>>t;
    while(t--){
        cin>>n>>m>>sx>>sy>>lvl;
        memset(grid, 0, sizeof grid);
        memset(visited, false, sizeof visited);
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        if(grid[sx][sy]){
            cout<< bfs(sx,sy,lvl)<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }

return 0;
}
/*

2
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0

5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1

Output
5
15
*/
