
/*
https://www.careercup.com/question?id=5652067409461248
https://pastebin.com/M6np7E6u
*/
#include<iostream>
#include<cstring>
using namespace std;
int grid[100][5], row;
bool valid(int x, int y){
    return(x>=0 && x < row && y >=0 && y < 5);
}
int maxCoinsCollecInPath(int r, int c, int boom, int effect){
    if(r<0) return 0;
    int ans  = 0, p =0;

    for(int i =-1; i<2; i++){
        int x = r - 1;
        int y = c + i;
        if(valid(x, y)){
            //Enemy
            if(grid[x][y]==2){
                if(boom == 0 && effect>0)
                    p = maxCoinsCollection(x,y,boom, effect-1);
                if(boom > 0)
                    p = maxCoinsCollection(x,y, 0, 5);
            }
            else{
                if(boom==1)
                   p = maxCoinsCollection(x,y, boom,5);
                else
                    p = maxCoinsCollection(x,y, boom,effect-1);
            }
        }
        ans = max(ans, p);
    }
    if(grid[r][c]==1) ans ++;
    return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>row;
        // for(int i =0; i<100; i++) for(int j=0; j<5; j++)grid[i][j] = 0;
        memset(grid,0,sizeof grid);
        for(int i =0; i<row; i++)
            for(int j=0; j<5; j++)
            cin>>grid[i][j];

       cout<<maxCoinsCollecInPath(row,2,1,0)<<endl;
    }

return 0;
}
/*
5
6
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1
*/
