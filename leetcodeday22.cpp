#include<bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  vector<int> beans = {2,10,3,2};
// int k =3;
  int threshold = 5;
  //int n = beans.size();
long long total = 0;
//int n = beans.size();
// for(int i=0;i<n;i++){
//    total += beans[i];
// }
// long long ans = 1e9;

// sort(beans.begin(), beans.end());
// for(int i=0;i<n;i++)
// {
//     long long val = total - ((k + 0L)*beans[i]);
//     k--;
   
//     ans = (long long)min(ans, val);
// }

    int num, k;
	cin>>num;
    cin>>k;
	vector<int> pre;
	while(num != 0){
		int d = num%10;
		num = num/10;
		pre.push_back(d);
	}
    for(auto &i: pre){
    	cout<<i<<endl;
    }
        
	int ans = 0;
	int n = pre.size();
	if(n == k) return -1;
	int left = n-k;
	for(int i=n-1;i>=k;i--){
		ans += pre[i];
		ans = ans*10;
	}
	cout<<ans<<endl;
}