#include<bits/stdc++.h>
using namespace std;
//return smallest number which can't be obtained from bitwise or
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> st;
    int arr[] = {1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int maxe = 
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
        int r = arr[i];
        for(int j=i+1;j<n;j++){
            r = r^arr[j];
            st.insert(r);
        }
    }

    for(int i=1;i<)
    
    return 0;
}