/*
https://www.careercup.com/question?id=5677905146281984
https://github.com/arjunsk/samsung_interview/blob/master/wormhole.cpp
https://gist.github.com/gunpreet34/b58c38b3556271059182244676ba06a1
https://hack.codingblocks.com/contests/c/782/870
https://discuss.codingblocks.com/t/test-case-of-minimum-time-traversal-problem/12944
http://ideone.com/Sbx7MA
*/

/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole.
It is ok if you wont use any warmhole.
*/
#include<iostream>
#include<vector>
using namespace std;
int grid[101][5], ans, totalHole, tmp;
int dis(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}
void minimumCostToReachGoal(int sX, int sY, int tX, int tY,bool visited[], int cost)
{
    ans = min(ans, dis(sX,sY,tX,tY)+cost);

    for(int i =0; i<totalHole; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            tmp = dis(sX,sY,grid[i][0],grid[i][1]) + grid[i][4] + cost;
            minimumCostToReachGoal(grid[i][2], grid[i][3], tX,tY, visited,tmp);

            tmp = dis(sX,sY,grid[i][2],grid[i][3]) + grid[i][4] + cost;
            minimumCostToReachGoal(grid[i][0], grid[i][1], tX, tY, visited, tmp);
            visited[i] = false;
        }
    }
}
int main()
{
    int testCase,sX,sY,tX,tY;
    cin>>testCase;
    for(int j=1; j<=testCase; j++){

        cin>>sX>>sY>>tX>>tY;
        cin>>totalHole;
        for(int i =0; i<totalHole; i++)
        {
            cin>>grid[i][0]>>grid[i][1]>>grid[i][2]>>grid[i][3]>>grid[i][4];
        }
        ans =INT_MAX;
        bool visited[totalHole] = {false};
        minimumCostToReachGoal(sX,sY,tX,tY,visited,0);
        cout << "Case " <<j<< "# " << ans<< endl;
    }

    return 0;
}
/*
3
0 0
100 100
3
1 2 120 120 2
4 5 120 100 3
6 8 150 180 4
0 0
100 100
3
1 2 120 120 2
4 5 120 100 3
6 8 102 102 4

0 0 1 1
3
1 2 120 120 16
2 5 120 100 21
6 8 150 180 16


*/
