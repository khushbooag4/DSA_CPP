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
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w" ,stdout);

    int n; cin>>n;
    // output is beautiful if arr[i] + i is a prime number or 0 or 1
    vector<int> ans(n,0);
    for(int i=1;i<n;i++){
    	ans[i] = ans[i-1] + 1;
    }
   
    vector<int> res = ans;
    while(next_permutation(ans.begin(), ans.end())){
    	bool flag = true;
    	for(int i=0;i<ans.size();i++){
    		if(isPrime(ans[i] + i) || ans[i] + i == 0 || ans[i] + i == 1) {
    			flag = false;
    		}else flag = true;
    	}
    	if(!flag){
    		res = ans;
    	}
    }

    for(int c: res){
    	cout<<c<<" ";
    }cout<<endl;
    


   return 0;
}