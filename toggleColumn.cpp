//https://www.geeksforgeeks.org/samsung-competency-test-25-aug-19/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int grid[100][100];
map<string, int>sameRowCnt;
string rowStr;
int zeroCnt;
int maxSameRow(int r, int c, int k){
    int ans = 0;
    for(int i =0; i<r; i++){
        rowStr = "";
        for(int j=0; j<c; j++){
            char x = '0' + grid[i][j];
            rowStr += x;
            if(grid[i][j]==0) zeroCnt++;
        }
        if(sameRowCnt[rowStr] !=0){
         if((k-zeroCnt%2==0)||(zeroCnt-k%2==0)){
            ans = max(ans , sameRowCnt[rowStr]);
         }
            sameRowCnt[rowStr] = 0;
        }
}

return ans;
}

int main(){
    int t,r,c,k;cin>>t;
    while(t--){
        cin>>r>>c>>k;
        for(int i =0; i<100; i++)for(int j=0; j<100; j++) grid[i][j] = 0;
         sameRowCnt.clear();

        for(int i =0; i<r; i++){
            rowStr = "";
            for(int j=0; j<c; j++){
                cin>>grid[i][j];
                char x = '0' + grid[i][j];
                rowStr += x;
            }
            sameRowCnt[rowStr]++;
        }
        cout<<maxSameRow(r,c, k)<<endl;
    }

return 0;
}
