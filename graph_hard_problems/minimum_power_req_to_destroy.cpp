#include<bits/stdc++.h>
using namespace std;

int dfs(int c, vector<vector<int>>& grp, vector<bool>& vis, vector<int>& arr){
   int val = arr[c-1];
   vis[c] = true;
   for(auto neigh: grp[c]){
    if(!vis[neigh]){
        val = max(val, dfs(neigh, grp, vis, arr));
    }
   }

   return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5, m = 2;
    vector<int> arr = { 2, 3, 4, 5, 6 };
    vector<vector<int> > conn = { { 1, 5 }, { 3, 4 } };


    cout<<"Connecting"<<endl;
    vector<vector<int>> gr(n+1);
    for(int i=0;i<n;i++){
       gr[i] = vector<int>();
    }
    
    for(int i=0;i<m;i++){
        gr[conn[i][0]].push_back(conn[i][1]);
        gr[conn[i][1]].push_back(conn[i][0]);
    }

    int ans = 0;
    vector<bool> visited(n, false);
    for(int i=1;i<n;i++){
        if(!visited[i]){
            ans += dfs(i, gr, visited, arr);
        }
    }

    cout<<ans<<endl;

    return 0;
}