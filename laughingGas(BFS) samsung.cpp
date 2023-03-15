////https://www.cnblogs.com/kingshow123/p/practicec1.html
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node{
    int x,y,level;
};

int grid[100][100];
int visited[100][100];
int xx[4] = {0,0,1,-1};
int yy[4] = {1,-1,0,0};
int main(){
    int T,n,m,r,c, ans; cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n>>m;
        memset(grid, 0, sizeof grid);
        memset(visited, 0, sizeof visited);
        for(int i =1; i<=m; i++)
            for(int j=1; j<=n; j++)
                cin>>grid[i][j];

        cin>>r>>c;
        queue <node> Q;
        node tmpNode1,tmpNode2;
        tmpNode1.x = c, tmpNode1.y = r, tmpNode1.level = 0;
        Q.push(tmpNode1);
        grid[tmpNode1.x][tmpNode1.y] = 2;// 2 for visited

        while(!Q.empty()){
            tmpNode1 = Q.front();
            Q.pop();
            for(int i =0; i<4; i++){
                tmpNode2.x = xx[i] + tmpNode1.x;
                tmpNode2.y = yy[i] + tmpNode1.y;
                tmpNode2.level = 1 + tmpNode1.level;
                ans = tmpNode2.level;
                if(grid[tmpNode2.x ][tmpNode2.y]==1){// only for not visited and person full cell
                    grid[tmpNode2.x][tmpNode2.y] = 2;// 2 for visited
                    Q.push(tmpNode2);
                }
            }
        }
       cout<<"Case "<<t<<"# "<<ans<<endl;
    }

return 0;
}

/*
2
7 8
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 1 1 1 1
0 1 1 1 1 1 1
0 1 0 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
2 5
*/
