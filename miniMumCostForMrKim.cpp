//https://www.careercup.com/question?id=5745468609921024
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, ans, x[100], y[100], visited[100];
int dis(int i, int j){
    int x1 = x[i], x2 = x[j];
    int y1 = y[i], y2 = y[j];
    return (abs(x2-x1)+abs(y2-y1));
}
void minimumCostForMrKim(int src, int cntNode, int cost){
    if(cntNode == n){
        ans = min(ans, cost + dis(src, n+1));
    }
    for(int i =1; i<=n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            minimumCostForMrKim(i,cntNode+1,cost + dis(src, i));
            visited[i] = 0;
        }
    }


}

int main(){
    int testCase; cin>>testCase;
    for(int t=1;t<= testCase; t++){
        cin>>n;
        memset(x, 0,sizeof x);
        memset(y, 0, sizeof y);
        cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int i =1; i<=n; i++){
            cin>>x[i]>>y[i];
        }
        memset(visited, 0, sizeof visited);
        ans = INT_MAX;
        minimumCostForMrKim(0,0,0);

     cout << "#" <<testCase<< " " << ans<< endl;
    }
return 0;
}
/*

100 100 70 40 30 10 10 5 90 70 50 20 0 0
3 -> Test Case
5
0 0 100 100 70 40 30 10 10 5 90 70 50 20
*/
