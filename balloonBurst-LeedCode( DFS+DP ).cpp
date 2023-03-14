//https://leetcode.com/problems/burst-balloons/
#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
vector<int>points;
int dp[100][100];

int maxPointCollection(int i, int j, int n){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;

    for(int indx = i; indx<=j; indx++){
        int l = (i==0)? 1 : points[i-1];
        int r = (j==n-1)? 1 : points[j+1];
        int cost = maxPointCollection(i, indx-1, n) + maxPointCollection(indx+1,j,n);
        if(i==0 && j==n-1) cost+=points[indx];
        else cost += (l*points[indx]*r);
        maxi = max(cost, maxi);
    }
    return dp[i][j] = maxi;
}



int main(){
    int t, n, ponit;cin>>t;
    while(t--){
        cin>>n;
        points.clear();
        for(int i=0; i<n; i++){
            cin>>ponit, points.push_back(ponit);
        }
        memset(dp, -1, sizeof(dp));
       cout<< maxPointCollection(0,n-1,n)<<endl;
    }

return 0;
}
/*
5
4
1 2 3 4
4
3 1 5 8
3
1 2 3
3
5 6 7
Output
40
167
12
252
*/

