/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and
the edge weights are the probabilities of the doctor going from that division to other connected division but the
doctor stays 10 mins at each division now there will be given time and had to find the division in which he will be
staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division
in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling
time is not considered and during that 10min at 10th min he will be in next division, so be careful
Input:
2
6 10 40
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
Output
6 0.774000
3 0.700000
*/

#include<iostream>
#include<vector>
#include<queue>
#define f first
#define s second
using namespace std;
vector<vector<pair<int, double>>> graph;
vector<bool>visited;
vector<double>prob;

void bfs(int root, int n, int time){
    queue< int > Q;
    double maxPro =0;
    int curCity = 0;


    Q.push(root);
    visited[root] = true;
    prob[root] = 1;

    while(!Q.empty()){
        int sz = Q.size();
        maxPro = 0;
        curCity = 0;
        while(sz--){
            int  u = Q.front();
            Q.pop();
            for(auto child : graph[u]){
                int v = child.f;
                double w = child.s;
                if(v != u){
                    prob[v] += prob[u]*w;
                    if(maxPro < prob[v]){
                        maxPro = prob[v];
                        curCity = v;
                    }
                }
                if(!visited[v]){
                    Q.push(v);
                    visited[v] = true;
                }
            }
        }
        time -=10;
        if(time==0) break;
    }
    cout<<"\n"<<curCity+1<<" "<<maxPro<<endl;
}

int main(){
    int t, node, edge, time, x,y;cin>>t;
    double pro;
        while(t--){
            cin>>node>>edge>>time;
            graph.clear();
            graph.resize(node);
            visited.clear();
            visited.assign(node, false);
            prob.clear();
            prob.assign(node,0);
            for(int i =0; i<edge; i++){
                cin>>x>>y>>pro;
                graph[x-1].push_back({y-1, pro});
            }
            bfs(0, node, time);
        }

return 0;
}
/*
4
6 10 10
1 2 0.7
1 3 0.3
3 3 0.2
3 4 0.8
2 4 1.0
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 10 10
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1.0
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 10 20
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1.0
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 10 30
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1.0
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 0.774000
3 0.700000
4 0.860000
5 0.774000

*/

