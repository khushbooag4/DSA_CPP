#include <bits/stdc++.h>
using namespace std;


vector<int> par;
    int findPar(int u){
       if(par[u] == u) return u;
       return par[u] = findPar(par[u]); 
    }

    void DSU(int u, int v){
        int upar = findPar(u);
        int vpar = findPar(v);

        par[vpar] = upar; 
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> graph;
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        for(auto g: allowedSwaps){
           int u = g[0];
           int v = g[1];
           DSU(u, v);
        }
        map<int, map<int,int>> mp;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            int root  = findPar(i);
            cout<<"ROOT"<<root<<endl;
            int num = source[i]; //value possible hai ise location(index)
            map<int, int> s;
            if(!mp.count(root)){
                mp[root] = s;
            }
            s = mp[root];
            if(!s.count(num)){
               s[num] = 1;
            }else s[num]++;
            mp[root] = s;
           
        }

        map<int, int> s = mp[1];
         for(auto im: s){
                cout<<im.first<<"---"<<im.second<<endl;
            }

        int ans = 0;
        for(int i=0;i<n;i++){
            int root = findPar(i);
            int t = target[i];
            map<int, int> s = mp[root];
            cout<<s[t]<<"---"<<endl;
            if(s.find(t) == s.end()){
                ans++;
                continue;
            }
            if(s[t] <= 0) ans++;
            else {
                s[t]--;
                if(s[t] == 0) s.erase(t);
            }
            cout<<s[t]<<"---"<<endl;
            mp[root] = s;
        }

        for(auto m: mp){
            map<int, int> s = m.second;
        }

        return ans;
    }

int main()
{

    int N = 4;
    vector<int> Edge = { 1, 2, 0, -1 };
    vector<int> source = {2, 3 , 1};
    vector<int> target = {1,2, 2}; 
    vector<vector<int>> allowedSwaps = {{0,2}, {1, 2}};
    // Function Call
    int ans = minimumHammingDistance(source, target, allowedSwaps);
 cout << ans <<"ANS"<<endl;
    return 0;
}