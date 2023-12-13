#include <bits/stdc++.h>
using namespace std;

  int findTheCity(int n, vector<vector<int>>& edges, int k) {
       //Floyd Warshall algo
        int dist[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = 1e9;
            }
        }

        for(auto& e: edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;k<n;k++){
              for(int j=0;k<n;k++){
                  dist[i][j] = min(dist[i][j],  dist[i][k] + dist[k][j]);
              }
            }
        }

        int smallest_size = INT_MAX, ans = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= k){
                    count++;
                }
            }
            if(count < smallest_size){
                smallest_size = count;
                ans = i;
            }
        }


        return ans;
    }

vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int count = 0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(boxes[i] == '1'){
                mp[i] = 1;
            }
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(auto m: mp){
            	cout<<m.first<<endl;
                cnt += abs(i - m.first);
            }
            cout<<"cnt"<<endl;

            ans.push_back(cnt);
        }


        return ans;
    }

int main()
{
    
    vector<int> ans = minOperations("110");
    for(auto a: ans)
    {
    	cout<<a<<endl;
    }
    return 0;
}