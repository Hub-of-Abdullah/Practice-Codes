//https://blog.csdn.net/broadCE/article/details/47959227
#include<iostream>
#include<cstring>
using  namespace std;
int n,ans, grid[100][100], visited[100][100];

bool isvalid (int x, int y){
return ((grid[x][y]==0 || grid[x][y]==2) && x>=0 && x<n && y>=0 && y<n);
}
int xx[4] = {0 ,0 ,-1,1};
int yy[4] = {-1,1, 0 ,0};

void maxJuwelCollection(int r, int c, int juwel){
    if(r==n-1 && c == n-1){
        if(juwel > ans ) ans = juwel;
    }
    for(int i =0; i<4; i++){
        int x = r + xx[i];
        int y = c + yy[i];

        if(isvalid(x,y) && visited[x][y] == 0){
            int juwelFound = (grid[x][y]==2) ? 1:0;
            visited[x][y] = 1;
            maxJuwelCollection(x,y, juwel + juwelFound);
            visited[x][y] = 0;
        }
    }
}


int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        memset(grid,0, sizeof grid);
        memset(visited,0, sizeof visited);
        for(int i =0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>grid[i][j];
        ans = 0;
        visited[0][0] = 1;
        maxJuwelCollection(0,0,0);
        cout<<ans<<endl;
    }
return 0;
}
/*
2
5
0 0 0 2 0
2 1 0 1 2
0 0 2 2 0
0 1 0 1 2
2 0 0 0 0
6
0 1 2 1 0 0
0 1 0 0 0 1
0 1 2 1 2 1
0 2 0 1 0 2
0 1 0 1 0 1
2 0 2 1 0 0

OutPut
6
4
*/
