//https://github.com/s-kachroo/SamsungPractice/blob/master/mr%20lee.cpp
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, ans, grid[100][100];
vector<bool> visited;

void minCostForMrLee(int src, int cntNode, int cost){
    if(cntNode == n){
        if(grid[src][1] != 0){
            ans = min(ans, cost + grid[src][1]);
        }
    }
    for(int i =1; i<=n; i++){
        if(grid[src][i] !=0 && !visited[i]){
            visited[i] = true;
            minCostForMrLee(i, cntNode+1, cost+grid[i][src]);
            visited[i] = false;
        }
    }
}

int main(){
    int t ; cin>>t;
    while(t--){
        cin>>n;
        memset(grid, 0, sizeof grid);
        for(int i =1; i<n; i++)
            for(int j =1; j<n; j++)
                cin>>grid[i][j];
        visited.resize(n+1, false);
        visited[1] = true;
        int ans = INT_MIN;
        minCostForMrLee(1,1,0);
        cout<<ans<<endl;
    }
return 0;
}
