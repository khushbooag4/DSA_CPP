#include<bits/stdc++.h>
using namespace std;

int par[10005];
int cnt[10005];
int find_par(int x){
    if(x == par[x]) return x;
    return par[x] = find_par(par[x]);
}

int count(int x){
    return cnt[find_par(x)];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5;
    int a[] = {1, 2, 2, 1};
    int b[] = {2, 3, 4, 5};

    for(int i=0;i<10000;i++){
        par[i] = i;
    }

    memset(cnt, 1, sizeof(cnt));
    int x, y;
    for(int i=0;i<n;i++){
        x = find_par(a[i]);
        y = find_par(b[i]);

        if(x == y) return;
        else{
            par[y] = x;
            cnt[y] += cnt[x];
        }
    }


    //number of tuples in integers 
    // i < j < k 
    // the give tree does not contain a simple path that include all 

    return 0;
}