#include <bits/stdc++.h>
using namespace std;

// Given 2  binary strings, your task is to make those 2 strings equal by performing following operation
// -> select any 2 adjacent characters from any string and flip/invert them i.e 0 -> 1 or 1 -> 0

// Find the minimum number of operations required to make 2 strings equal.

char flips(char c){
	if(c == '1') return '0';
	else return '1';
}

int minOp(string a, string b){
	//base condition
	if(a.size() != b.size()) return -1;
	int n = a.size();
	int minop = 0;
	int i=0;
	while(i < n-1){
		if(a[i] == b[i]){
			i++;
		}else{
			a[i] = b[i];
			minop++;
			a[i+1] = flips(a[i+1]);
			i++;
		}
		cout<<a<<"---"<<endl;
	}
    cout<<b<<"--"<<endl;
	if(a != b) return -1;

	return minop;
}

int main()
{

    string s1 = "0101";
    string s2 = "1111";
    // Function Call
    int ans = minOp(s1, s2);
 cout << ans <<"ANS"<<endl;
    return 0;
}