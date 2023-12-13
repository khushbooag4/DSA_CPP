// Ques1) https://www.geeksforgeeks.org/last-node-at-which-frog-is-standing-after-t-seconds/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Hello World";
    vector<vector<int>> edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    int t = 2, target = 3;
    unordered_map<int, vector<int>> gr;
    for(auto& e: edges){
        gr[e[0]].push_back(e[1]);
        gr[e[1]].push_back(e[0]);
    }
    
    queue<vector<int>> q;
    //root  | parent | time | probality of getting target node in between the path
    q.push({1, -1, 0, 0});
    int time = 0;
    while(!q.empty()){
        auto n = q.size();
        while(n--){
            auto node = q.front();
            q.pop();
            //node - vector<int>
            if(node[2] == t) {
                if(node[0] == target || node[3] == 1){
                    cout<<node[0]<<endl;
                    return 0;
                }
                continue;
            }
            int child = gr[node[0]].size(); //no of childs
            if(node[0] != 1) child--;
            
            if(child == 0){//no child further     
                if(node[0] == target || node[3] == 1){
                    cout<<node[0]<<endl;
                    return 0;
                }
                continue;
            }
            cout<<"size of children of graph "<<child<<endl;
            for(auto neigh: gr[node[0]]){
                if(neigh == node[1]){
                    //node == parent cycle
                    continue;
                }
                vector<int> res(4);
                res[0] = neigh;
                res[1] = node[0];
                res[2] = node[2] + 1;
                res[3] = (node[0] == target) ? 1 : 0;
                q.push(res);
            }
        }
    }
    

    return 0;
}
