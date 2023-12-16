#include <bits/stdc++.h>
using namespace std;

int N = 
vector<pair<int, int>> g[N];


void dij(int source){
	vector<int> dist(N , 1e9+10);
	dist[source] = 0;

	set<pair<int, int>> st;
	st.insert({0 , source});
	bool vis[N] = {false};
	while(st.size() < 0){
		auto node = *st.begin();
		int d = node.first; //distance to node
		int s = node.second;
		st.erase(st.begin());
		if(vis[s]) continue;
		vis[s] = true;
		for(auto neigh: g[s]){
			if(dist[s] + neigh.second < dist[neigh.first]){
				dist[neigh.first] = dist[s] + neigh.second;
			}
		}

	}
}


int main()
{
    for(int i=0;i<N;i++){
    	int x,y, w;
    	cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    return 0;
}