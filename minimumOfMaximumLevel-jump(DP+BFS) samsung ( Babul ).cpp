/*
Row borarbor...
    parent = 1 and child = 1 hle parent value copy
------------------------------------------------
Column borabor...
 value 1 kore bridhi pabe...
    parent = 0 and child = 0
    parent = 0 and child = 1
    parent = 3 and child = 0
    parent = 2 and child any (1 or 0)
and value max(1, parent value) hbe..jokhon
    parent = 1 and child = 1
    parent = 1 and child = 0
-------------------------------------
child already visited hole insert min value in both cell of child  and parent cell
*/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
    int x,y,px,py;
};

int row, col,sx,sy,dx,dy;
int grid[100][100];
bool visited[100][100];
int DP[100][100];

int mx[4] = {0, 0,-1, 1};
int my[4] = {1,-1, 0, 0};

bool isValid(int x, int y){
    return (x>=0 && x<row && y>=0 && y<col);
}

void bfs(int sx,int sy, int dx, int dy){
    queue< node >Q;
    Q.push({sx,sy,INT_MAX,INT_MAX});
    visited[sx][sy] = true;
    DP[sx][sy] = 0;
    node tmpNode1;

    while(!Q.empty()){
        tmpNode1 = Q.front(); Q.pop();
        for(int i =0; i<4; i++){
            int x = mx[i] + tmpNode1.x, y = my[i] + tmpNode1.y; // Child node Index---

                if(isValid(x,y) && (x != tmpNode1.px || y != tmpNode1.py)){//Only valid and not parent cell consider

                    //LEFT - RIGHT
                    if(i<2 && grid[x][y] != 0 && grid[tmpNode1.x][tmpNode1.y] != 0){
                        if(!visited[x][y]){
                            DP[x][y] = DP[tmpNode1.x][tmpNode1.y];
                            Q.push({x,y,tmpNode1.x,tmpNode1.y});
                            visited[x][y] = true;
                        }
                        else{
                            DP[x][y] = min(DP[x][y], DP[tmpNode1.x][tmpNode1.y]);
                            DP[tmpNode1.x][tmpNode1.y] = DP[x][y];
                        }
                       /* if(!visited[x][y]){
                            Q.push({x,y,tmpNode1.x,tmpNode1.y});
                            visited[x][y] = true;
                        }*/
                    }
                    //UP-DOWN
                    else if(i>1){
                        if(!visited[x][y]){
                            if((grid[tmpNode1.x][tmpNode1.y]==2) || (grid[x][y] == 0 && grid[tmpNode1.x][tmpNode1.y]==0) || (grid[x][y]==1 && grid[tmpNode1.x][tmpNode1.y]==0)||(grid[x][y]==3 && grid[tmpNode1.x][tmpNode1.y]==0)){
                            DP[x][y] = DP[tmpNode1.x][tmpNode1.y] +1;
                            }
                            else{
                            DP[x][y] = max(1, DP[tmpNode1.x][tmpNode1.y]);
                            }
                            Q.push({x,y,tmpNode1.x,tmpNode1.y});
                            visited[x][y] = true;
                        }
                        else{
                            DP[x][y] = min(DP[x][y], DP[tmpNode1.x][tmpNode1.y]);
                            DP[tmpNode1.x][tmpNode1.y] = DP[x][y];
                        }
                    }
            }
        }
    }

}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>row>>col;
        memset(grid, 0, sizeof grid);
        memset(visited, 0, sizeof visited);
        memset(DP, 0, sizeof DP);

        for(int i=0;i<row;i++)
            for(int j = 0; j<col; j++){
                cin>>grid[i][j];
                if(grid[i][j]==2){sx = i; sy = j;}//source(sx,sy)
                if(grid[i][j]==3){dx = i; dy = j;}//destination(dx,dy)
        }
       bfs(sx,sy, dx,dy);
       cout<<DP[dx][dy]<<endl;
    }

return 0;
}
/*

INPUT
5
3 3
1 1 3
1 0 0
2 0 0

5 6
1 0 1 1 3 1
1 0 1 0 1 1
0 0 0 0 0 0
0 0 0 0 0 0
1 1 2 1 1 1

5 12
1 0 1 0 1 0 1 0 1 1 0 1
1 0 1 1 1 1 1 0 1 3 1 1
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0
1 1 2 1 1 1 1 1 1 1 1 1

4 13
1 1 1 1 1 3 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0 0 0 0 0

4 12
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 3 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
2 1 1 1 1 1 1 1 1 1 1 1


OUTPUT
1
3
2
3
1
*/
