// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

vector<int> vis, par, tmp;
long long dfs(int node, int p, unordered_map<int, vector<int> >& v)
{
    vis[node] = 1;
    par[node] = p;
    for(auto neigh: v[node]){
        if(!vis[neigh]){
            long long res = dfs(neigh, node, v);
            if(res != -1){
                return res;
            }
        }else if(vis[neigh]){
            long long sum = neigh;
            while(node != neigh){
                sum += node;
                node = par[node]; //parents visit m cycle jab tk same point na aajaye 1-> 0 -> 2 - >1
            }
            if(node == neigh){ //cycle start and end point
                return sum;
            }return -1;
        }
    }
    return -1;
}

// Function to find largest sum cycle
long long largestSumCycle(int N, vector<int> Edge)
{
    long long ans = -1;
    vis = vector<int>(N);
    unordered_map<int, vector<int>> v;
    par = vector<int>(N);

    for (int i = 0; i < N; i++) {
        if (Edge[i] != -1) {
            v[i].push_back(Edge[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            ans = max(ans, dfs(i, -1, v));
        }
    }

    return ans;
}

// Drivers code
int main()
{

    int N = 4;
    vector<int> Edge = { 1, 2, 0, -1 };

    // Function Call
    int ans = largestSumCycle(N, Edge);
    cout << ans;
    return 0;
}