#include<bits/stdc++.h>
using namespace std;

double bfs(string start, string end, unordered_map<string, vector<pair<string, double>>> &adj){
        queue<pair<string, double>> q;
        q.push({start, 1.0});
        unordered_set<string> visited;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string node = q.front().first;
                double cost = q.front().second;
                q.pop();
                if(!adj.count(node)) continue;
                if(node == end) return cost;
                for(auto& neigh: adj[node]){
                    if(!visited.count(neigh.first)){
                        q.push({neigh.first, cost*neigh.second});
                        visited.insert(neigh.first);
                    }
                }
            }
        }

        return -1.0;
    }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int x,y;
  cin>>x>>y;
  vector<vector<string>> equations = {{"a","b"},{"b","c"}};
  vector<double> values = {2.0,3.0};
  vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
  unordered_map<string, vector<pair<string, double>>> v;
        vector<double> ans;
        int n = equations.size();
        int q = queries.size();
        for(int i=0;i<n;i++){
            string x = equations[i][0];
            string y = equations[i][1];
            double w = values[i];
            v[x].push_back({y, w});
            v[y].push_back({y, (double)1.0/w});
        }
        int res = 1.0;
        for(int i=0;i<q;i++){
            double value = (double)bfs(queries[i][0], queries[i][1], v);
            cout<<value<<endl;
        }
}