//https://github.com/s-kachroo/SamsungPractice/blob/master/mr%20lee.cpp
#include<bits/stdc++.h>
using namespace std;
int n, result;
vector< vector< int >> graph;

void minCostForMrLee(int src, bool visited[], int cntNode, int cost){
    if(cntNode == n){
        if(graph[src][1] != 0)
        result = min(result, cost + graph[src][1]);
    }
    for(int i =1; i<=n; i++){
        if(!visited[i] && graph[src][i] != 0){
            visited[i] = true;
            minCostForMrLee(i,visited,cntNode+1,cost +graph[src][i]);
            visited[i] = false;
        }
    }
}

int main(){
    int t;cin>>t;
    for(int testCase =1; testCase<=t; testCase++){
        cin>>n;
        graph.clear();

        graph.resize(n+1, vector<int>(n+1,0));
        for(int i =1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>graph[i][j];
            }
        }
        bool visited[n+1] = {false};
        visited[1] = true;
        result = INT_MAX;
        minCostForMrLee(1, visited, 1,0);
        cout<<result<<endl;
    }
}
/*
Mr. Lee has to travel various offices abroad to assist branches of each place. But he has a problem. 
The airfare would be real high as all offices he has to visit are in foreign countries. He wants to visit every 
location only one time and return home with the lowest expense. Help this company-caring man calculate the lowest expense.
Input format
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. 
After that, the test cases as many as T (T ≤ 30) are given in a row. N, the number of offices to visit is given on 
the first row per each test case. At this moment, No. 1 office is regarded as his company (Departure point). 
(1 ≤ N ≤ 12) Airfares are given to move cities in which branches are located from the second row to N number rows.
i.e. jth number of ith row is the airfare to move from ith city to jth city. If it is impossible to move between 
two cities, it is given as zero.
Output format
Output the minimum airfare used to depart from his company, visit all offices, and then return his company on the 
first row per each test case.
Example of Input
3
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0
5
9 9 2 9 5
6 3 5 1 5
1 8 3 3 3
6 0 9 6 8
6 6 9 4 8
3
0 2 24
3 0 2
0 4 0
Example of Output
30
18
CUSTOM - 31 <- 4
*/
