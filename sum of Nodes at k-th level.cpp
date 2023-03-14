// https://www.geeksforgeeks.org/sum-nodes-k-th-level-tree-represented-string/
#include<iostream>
using namespace std;

int sumOfKthLevel(string tree, int k){
    int n = tree.size(), sum =0, level=-1;
    for(int i =0; i<n; i++){
        if(tree[i] == '(') level++;
        else if(tree[i] == ')') level--;
        else{
            if(level == k) sum += tree[i]-'0';
        }
    }
    return sum;
}


int main(){
    string tree  = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
    int k= 2;
    cout<<sumOfKthLevel(tree, k)<<endl;
return 0;
}
