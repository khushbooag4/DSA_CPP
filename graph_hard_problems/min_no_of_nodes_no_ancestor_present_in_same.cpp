#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //finding the level order traversal, count of the level 
    //maximum depth of the tree
    int par[] =  { 0 , -1, 1, 1, 2, 2, 5, 6 };
    int n = sizeof(par)/sizeof(par[0]);
    vector<int> child[n+1];
    //root - 1
    for(int i=1;i<n;i++){
        if(par[i] != -1){
            child[par[i]].push_back(i);//parent - child
        }
    }
    for(auto c: child){
        for(auto i: c){
            cout<<i<<endl;
        }
    }
    int res = 0;

    return 0;
}