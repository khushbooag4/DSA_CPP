#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return false;
        return true;
    }
}

int main(){     

        vector<int> nums = {1, 200, 2004, 6};
        int maxele = *max_element(nums.begin(), nums.end());
        int minele = *min_element(nums.begin(), nums.end());
        cout<<maxele << " " << minele<<endl;

        int n= 18;
        vector<int> sq(n+1);
        map<int,int> mp;
        int ans = 0;
        for(int i=1;i<=n;i++){
           sq[i] = i*i;
           mp[i*i] = i; 
        }

        // 1 - 1
        // 4 - 2
        // 9 - 3
        // 16 - 4
        // 25 - 5


        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sum = sq[i] + sq[j];
            //cout<<sum<<"sum"<<endl;
                if(mp.find(sum) != mp.end()){
                    ans += 2;
                }
            }
        }

        cout<<ans<<endl;
    }