// cycle - save the parent node of evry node, if there we found already visited one
// and it's not its parent of the current node
// then this is a cycle - we will, its length - 3
// if the grand parent of the current node is
#include<bits/stdc++.h>
using namespace std;

void findCycle(int curr, vector<vector<int>> &grh,  vector<int> &par, int parent){
    par[curr] = parent;
    for(auto child: grh[curr]){
        if(par[child] == -1){
            par[child] = curr;
            findCycle(child, grh, par, curr);
        }else if(child != parent){
            //check condition
            if(parent != -1 && par[parent] == child){
                //grandparent is the child - length of the cycle is 3
                // child node parent
                int edges = grh[child].size()
            }
        }
    }
}



int main(){
    int n = 6;//no of nodes;
    vector<vector<int>> edges = {{1, 2}, {2, 4}, {2, 5}, {3, 5}, {4, 5}, {5, 6}};
    
    vector<vector<int>> grh(n+1);
    for(auto e: edges){
        grh[e[0]].push_back(e[1]);
        grh[e[1]].push_back(e[0]);
    }
    vector<int> visited(n+1, false);

    vector<int> par(v+1, -1);//parent of every node
    for(int i=1;i<=n;i++){
        if(par[i] == -1){
            findCycle(i, grh, par, -1);
        }
    }

    return 0;
}