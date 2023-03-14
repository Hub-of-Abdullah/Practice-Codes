/*
    https://www.codingninjas.com/codestudio/problems/minimum-steps-to-reach-target-by-a-knight_893050?leftPanelTab=0
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct node{
    int x,y,lvl;
};
bool visited[100][100];
int n;

bool isValid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n && !visited[x][y]);
}

int xx[8] = {1,1,-1,-1,2,-2,-2,2};
int yy[8] = {2,-2,-2,2,1,1,-1,-1};

int bfs(int sx, int sy, int dx, int dy){
    queue< node > Q;
    Q.push({sx,sy,0});
    visited[sx][sy] = true;
    node tmpNode1, tmpNode2;

    while(!Q.empty()){
        tmpNode1 = Q.front();
        Q.pop();

        for(int i =0; i<8; i++){
            int x = tmpNode1.x + xx[i];
            int y = tmpNode1.y + yy[i];
            int lv = tmpNode1.lvl + 1;

            if(dx == x &&  dy == y) return lv;

            if(isValid(x,y)){
                Q.push({x,y,lv});
                visited[x][y] = true;
            }
        }
    }
}

int main(){
    int t, sx,sy,dx,dy;cin>>t;
    while(t--){
        cin>>n;
        cin>>sx>>sy;//Source
        cin>>dx>>dy;//Destination
        memset(visited, false, sizeof visited);
        cout<<bfs(sx,sy,dx,dy)<<endl;
    }
return 0;
}
