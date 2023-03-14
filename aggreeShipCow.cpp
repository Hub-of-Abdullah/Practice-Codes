/*
You are given an array of integers representing available positions and an integer c(cows).
Now you have to choose c positions such that the minimum difference between cows is maximized.
And all positions.
First line Test Case.
Second line N is the number of positions and c is the number of cows.
The third line is the position of the array.
For example,
Input
1
5 3
1 3 5 8 10
Output:
4 ---> minimum difference between cows is maximized.
1 5 10 ---> The positions
*/
#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
vector<int> allTempPositions;
vector<int> allPositions;


bool check(int mid,int index[],int n, int cow){
        int cowPositonCounter = 1, lastCowPostion = 0;
        allTempPositions.clear();
        allTempPositions.push_back(index[0]);

        for(int i = 1; i<n; i++){
            if(abs(index[i]-index[lastCowPostion])>= mid){
                cowPositonCounter++;
                lastCowPostion = i;
                 allTempPositions.push_back(index[i]);
            }
            if(cowPositonCounter == cow) return true;
        }
    return false;
}

int main(){
    int t,position,cow,ans; cin>>t;
    while(t--){
        cin>>position>>cow;
        int index[position];
        for(int i=0; i<position; i++)cin>>index[i];
        sort(index, index+position);
        int l = 0, r = index[position-1] - index[0], mid;

        while(r-l>0){
            mid = (l+r+1)/2;
            if(check(mid,index,position, cow)){
                ans = mid;
                l = mid;
                allPositions.clear();
                allPositions = allTempPositions;
            }
            else{
                r = mid-1;
            }
        }
        cout<<ans<<endl;
        for(auto p:allTempPositions)
            cout<<p<<" ";
        cout<<endl;

    }
return 0;
}
