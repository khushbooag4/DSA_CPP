#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = abs(s[i] - t[i]) ;
        }

        sort(res.begin(), res.end());
        int i = 0;
        for(i=0;i<n;i++){
           if(maxCost > 0 && maxCost >= res[i]){
                maxCost -= res[i];
                ans++;
           }
           else break;
cout<<maxCost<<" ";
        }cout<<endl;

        for(auto r: res){
            cout<<r<<endl;
        }return ans;
    }


int getLen(int num){
        int cnt = 0;
        while(num > 0){
            num = num/10;
            cout<<num<<endl;
            cnt++;
        }

        if(num < 0) cnt += 1;
        return cnt;
    }

void findColumnWidth(vector<vector<int>>& grid) {
    int n = grid.size();
    int m= grid[0].size();

    vector<int> ans(m);
    for(int i=0;i<m;i++){
        int maxm = 0;
        for(int j=0;j<n;j++){
            int length = getLen(grid[j][i]);
            maxm = max(maxm, length);
        }
        ans[i] = maxm;
    }

    for(auto m: ans){
      cout<<m<<endl;
    }
}
    
int main(){
    vector<vector<int>> grid = {{-15,1,3},{15,7,12},{5,6,-2}};
    findColumnWidth(grid);
    return 0;
}