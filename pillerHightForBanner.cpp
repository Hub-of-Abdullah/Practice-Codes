/*
https://www.geeksforgeeks.org/samsung-r-d-noida-question-september-2018/
https://code.hackerearth.com/8ca41dM?key=54591adea7ca921ac55169b10f163508
You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner
standing on top of TWO PILLERS.
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height
of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2.
In case, there is no combination possible, print 0.
INPUT :
1
5
1 2 3 4 6
Output :
8
*/
#include<vector>
#include<iostream>
using namespace std;
vector<int>arr;
vector<int>pre;
vector<int>cur;

int knapSack(int bag, int n){
    for(int i =1; i<=n; i++){
        for(int j = bag; j>=1; j--){
            if(j>=arr[i-1]){
                cur[j] = pre[j-arr[i-1]] + arr[i-1];
                pre[j] = cur[j];
            }
        }
    }
    return cur[bag];
}
int main(){
    int t,n,target,ans, sum; cin>>t;
    while(t--){
        cin>>n;
        arr.resize(n,0);
        sum = 0;
        ans =0;
        for(int i =0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        target = sum / 2;
        if(sum % 2==0){
            pre.resize(target+1, 0);
            cur.resize(target+1, 0);
            if(target == sum -knapSack(target,n))
                ans = target;
        }
        cout<<ans<<endl;
    }
return 0;
}
/*
1
5
1 2 3 4 6
Output :
8
*/
