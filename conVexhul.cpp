/*
    https://leetcode.com/problems/erect-the-fence/description/
*/
#include<iostream>
#include<cstring>
#include<vector>
#include <algorithm>
#define f first
#define s second

using namespace std;
vector<pair<int, int>> points;
vector<pair<int, int>> ans;

int slopCheck(pair<int, int>&p, pair<int, int> &q, pair<int, int> &r){
    return ((p.f * q.s + q.f * r.s + r.f * p.s) - ( q.f* p.s + r.f * q.s + p.f * r.s));
}
void conVexHull(int n){
    sort(points.begin(),points.end());
    for(int i =0;i<n; i++){
            while(ans.size()>1 && slopCheck(ans[ans.size()-2], ans.back(), points[i])<0){
                ans.pop_back();
            }
        ans.push_back(points[i]);
    }
    if(ans.size() != n){
       for(int i =n-2;i>=0; i--){
            while(ans.size()>1 && slopCheck(ans[ans.size()-2], ans.back(), points[i])<0){
                ans.pop_back();
            }
        ans.push_back(points[i]);
        }
    }
    ans.pop_back();

    cout<<endl;
    cout<<endl;
    for(auto x : ans)
        cout<<x.f<<" "<<x.f<<endl;

}
int main(){
    int t,n,x,y;cin>>t;
    while(t--){
        cin>>n;
        points.clear();
        ans.clear();
        for(int i =0; i<n; i++){
            cin>>x>>y;
            points.push_back({x,y});
        }
        conVexHull(n);
    }
    return 0;
}
/*
1
6
1 1
2 2
2 0
2 4
3 3
4 2


O/P
1 1
2 0
4 2
3 3
2 4

*/
