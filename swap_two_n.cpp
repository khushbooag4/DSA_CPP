#include<bits/stdc++.h>
using namespace std;

// Alice wants to distribute the students of the class into two teams 
//such that each student belongs to exactly one team and the uniqueness 
//of each team is exactly k
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int x,y;
  cin>>x>>y;
  //cout<<x<<y<<"Before"<<endl;
   x = x + y; // x now becomes 15
    y = x - y; // y becomes 10
    x = x - y; // x becomes 5
    cout << "After Swapping: x =" << x << ", y=" << y;
}