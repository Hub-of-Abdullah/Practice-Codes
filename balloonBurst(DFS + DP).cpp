#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int dp[100][100], points[100];
int maxPointCollection(int i, int j, int n){
    if(i>j)return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;

    for(int ind = i; ind <=j; ind++){
        int l = (i==0)? 1:points[i-1];
        int r = (j==n-1)? 1:points[j+1];
        int point = maxPointCollection(i, ind-1, n) + maxPointCollection(ind+1, j, n);
        if(i==0 && j==n-1) point += points[ind];
        else point += (l*r);
        maxi = max(maxi, point);
    }
return dp[i][j] = maxi;
}


int main(){
    int t, n,x; cin>>t;
    while(t--){
        cin>>n;
        memset(points, 0, sizeof(points));
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++){
            cin>>points[i];
        }
        cout<<maxPointCollection(0,n-1, n)<<endl;
    }
return 0;
}
/*
There are n balloons and n bullets and each balloon is assigned a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1. the multiplication of points assigned to the balloon on left and that of the right side.
2. point assigned to the left if no right exists
3. point assigned to the right if no left exists.
4. the point assigned to itself if no other balloon exists.
You have to output the maximum no of points possible.
Input
4
4
1 2 3 4
4
3 1 5 8
3
1 2 3
3
5 6 7
Output
20
55
9
49
Explanations for (5 6 7)
Blast Oder 6, 5, 7
when blast 6 then array become 5 7 and ans = (5*7)
when blast 5 then array become 7 ans ans = (5*7) + 7
when blast 7 then array become empty ans ans = (5*7) + 7 +7
*/
